//
//  @author raver119@gmail.com
//

#ifndef LIBND4J_HEADERS_TPARTY_H
#define LIBND4J_HEADERS_TPARTY_H

#include <ops/declarable/headers/common.h>

namespace nd4j {
    namespace ops {
        #if defined(__ALL_OPS) || defined(__CLION_IDE__) || defined(__firas_sparse)
        DECLARE_CUSTOM_OP(firas_sparse, 1, 1, false, 0, -1);
        #endif

        #if defined(__ALL_OPS) || defined(__CLION_IDE__) || defined(__test_scalar)
        DECLARE_CUSTOM_OP(test_scalar, 1, 1, false, 0, 0);
        #endif
    }
}

#endif