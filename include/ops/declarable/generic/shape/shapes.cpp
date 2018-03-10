//
//  @author raver119@gmail.com
//

#if defined(__ALL_OPS) || defined(__CLION_IDE__) || defined(__shapes_of)

#include <ops/declarable/CustomOperations.h>

namespace nd4j {
    namespace ops {
        CUSTOM_OP_IMPL(shapes_of, -1, -1, false, 0, 0) {
            for (int e = 0; e < block.width(); e++) {
                auto x = INPUT_VARIABLE(e);
                auto z = OUTPUT_VARIABLE(e);

                for (int i = 0; i < x->rankOf(); i++)
                    z->putIndexedScalar(i, x->sizeAt(i));
            }

            return ND4J_STATUS_OK;
        };
        DECLARE_SYN(shape_n, shapes_of);

        DECLARE_SHAPE_FN(shapes_of) {
            auto shapeList = SHAPELIST();

            for (int e = 0; e < inputShape->size(); e++) {
                auto inShape = inputShape->at(e);

                int *newshape;
                ALLOCATE(newshape, block.getWorkspace(), shape::shapeInfoLength(1), int);
                shape::shapeVector(shape::rank(inShape), newshape);

                shapeList->push_back(newshape);
            }

            return shapeList;
        };
    }
}

#endif