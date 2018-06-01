//
// Created by ernest on 18-6-2.
//

// An extension of DoW2
//      Add saveTotxt(), readFromtxt()
// Define ORBVocabulary

#ifndef DBoW2_EXT_TEMPLATEDVOCABULARYEXT_H
#define DBoW2_EXT_TEMPLATEDVOCABULARYEXT_H

#include <cassert>

#include <vector>
#include <numeric>
#include <fstream>
#include <string>
#include <algorithm>
#include <opencv2/core/core.hpp>
#include <limits>

#include "FeatureVector.h"
#include "BowVector.h"
#include "ScoringObject.h"

#include "../DUtils/Random.h"

#include <DBoW2/TemplatedVocabulary.h>
#include <DBoW2/FORB.h>

using namespace std;

namespace DBoW2 {

    template<class TDescriptor, class F>
    class TemplatedVocabularyExt : public TemplatedVocabulary<TDescriptor, F> {
        using TemplatedVocabulary<TDescriptor,F>::m_nodes;
        using TemplatedVocabulary<TDescriptor,F>::m_words;
        using TemplatedVocabulary<TDescriptor,F>::m_k;
        using TemplatedVocabulary<TDescriptor,F>::m_L;
        using TemplatedVocabulary<TDescriptor,F>::m_scoring;
        using TemplatedVocabulary<TDescriptor,F>::m_weighting;
        using TemplatedVocabulary<TDescriptor,F>::createScoringObject;

    public:
        /**
         * Loads the vocabulary from a text file
         * @param filename
         */
        bool loadFromTextFile(const std::string &filename);

        /**
         * Saves the vocabulary into a text file
         * @param filename
         */
        void saveToTextFile(const std::string &filename) const;

        void print();
    };

    template<class TDescriptor, class F>
    bool TemplatedVocabularyExt<TDescriptor, F>::loadFromTextFile(const std::string &filename) {

        ifstream f;
        f.open(filename.c_str());

        if (f.eof())
            return false;

        m_words.clear();
        m_nodes.clear();

        string s;
        getline(f, s);
        stringstream ss;
        ss << s;
        ss >> m_k;
        ss >> m_L;
        int n1, n2;
        ss >> n1;
        ss >> n2;

        if (m_k < 0 || m_k > 20 || m_L < 1 || m_L > 10 || n1 < 0 || n1 > 5 || n2 < 0 || n2 > 3) {
            std::cerr << "Vocabulary loading failure: This is not a correct text file!" << endl;
            return false;
        }

        m_scoring = (ScoringType) n1;
        m_weighting = (WeightingType) n2;
        createScoringObject();

        // nodes
        int expected_nodes =
                (int) ((pow((double) m_k, (double) m_L + 1) - 1) / (m_k - 1));
        m_nodes.reserve(expected_nodes);

        m_words.reserve(pow((double) m_k, (double) m_L + 1));

        m_nodes.resize(1);
        m_nodes[0].id = 0;
        while (!f.eof()) {
            string snode;
            getline(f, snode);
            stringstream ssnode;
            ssnode << snode;

            int nid = m_nodes.size();
            m_nodes.resize(m_nodes.size() + 1);
            m_nodes[nid].id = nid;

            int pid;
            ssnode >> pid;
            m_nodes[nid].parent = pid;
            m_nodes[pid].children.push_back(nid);

            int nIsLeaf;
            ssnode >> nIsLeaf;

            stringstream ssd;
            for (int iD = 0; iD < F::L; iD++) {
                string sElement;
                ssnode >> sElement;
                ssd << sElement << " ";
            }
            F::fromString(m_nodes[nid].descriptor, ssd.str());

            ssnode >> m_nodes[nid].weight;

            if (nIsLeaf > 0) {
                int wid = m_words.size();
                m_words.resize(wid + 1);

                m_nodes[nid].word_id = wid;
                m_words[wid] = &m_nodes[nid];
            } else {
                m_nodes[nid].children.reserve(m_k);
            }
        }

        return true;

    }


    template<class TDescriptor, class F>
    void TemplatedVocabularyExt<TDescriptor, F>::saveToTextFile(const std::string &filename) const {
        fstream f;
        f.open(filename.c_str(), ios_base::out);
        f << m_k << " " << m_L << " " << " " << m_scoring << " " << m_weighting << endl;

        for (size_t i = 1; i < m_nodes.size(); i++) {
            const typename TemplatedVocabulary<TDescriptor,F>::Node &node = m_nodes[i];

            f << node.parent << " ";
            if (node.isLeaf())
                f << 1 << " ";
            else
                f << 0 << " ";

            f << F::toString(node.descriptor) << " " << (double) node.weight << endl;
        }

        f.close();
    }

    template<class TDescriptor, class F>
    void TemplatedVocabularyExt<TDescriptor, F>::print(){
        std::cout << "Link Succeed" << std::endl;
    };

}

#endif //LOOP_DETECTION_TEMPLATEDVOCABULARYEXT_H
