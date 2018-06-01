//
// Created by ernest on 18-6-2.
//

// An extension of DoW2
//      Add saveTotxt(), readFromtxt()

#ifndef LOOP_DETECTION_TEMPLATEDVOCABULARYEXT_H
#define LOOP_DETECTION_TEMPLATEDVOCABULARYEXT_H

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

using namespace std;

namespace DBoW2 {
    template<class TDescriptor, class F>
    class TemplatedVocabularyExt : public DBoW2::TemplatedVocabulary {
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
    };

}


#endif //LOOP_DETECTION_TEMPLATEDVOCABULARYEXT_H
