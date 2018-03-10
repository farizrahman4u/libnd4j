//
// Created by raver119 on 10.02.18.
//
#if defined(__ALL_OPS) || defined(__CLION_IDE__) || defined(__tf_atan2)

#include <ops/declarable/headers/parity_ops.h>

namespace nd4j {
    namespace ops {

        OP_IMPL(tf_atan2, 2, 1, true) {
            auto y = INPUT_VARIABLE(0);
            auto x = INPUT_VARIABLE(1);
            auto z = OUTPUT_VARIABLE(0);

            x->template applyPairwiseTransform<simdOps::Atan2<T>>(y, z, nullptr);

            return Status::OK();
        }
    }
}

#endif