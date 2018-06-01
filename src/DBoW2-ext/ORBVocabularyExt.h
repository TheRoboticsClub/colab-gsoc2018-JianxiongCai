//
// Created by ernest on 18-6-2.
//

#ifndef DBoW2_EXT_ORBVOCABULARYEXT_H
#define DBoW2_EXT_ORBVOCABULARYEXT_H

#include <DBoW2.h>
#include <DBoW2/FORB.h>
#include "TemplatedVocabularyExt.h"

// define ORBVocabulary
namespace MapGen {
    typedef DBoW2::TemplatedVocabularyExt<DBoW2::FORB::TDescriptor, DBoW2::FORB>
            ORBVocabularyExt;
}

#endif //LOOP_DETECTION_ORBVOCABULARYEXT_H
