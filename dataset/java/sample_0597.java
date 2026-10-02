public class sample_0597 {

    static class CoordinateTransformer {
        double[][] matrix;

        CoordinateTransformer(double[][] matrix) {
            this.matrix = matrix;
        }

        double[] transform(double[] vector) {
            double[] result = {0, 0, 0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    result[i] += matrix[i][j] * vector[j];
                }
            }
            return result;
        }
    }

    static class TransformationChain {
        CoordinateTransformer[] transformers;

        TransformationChain(CoordinateTransformer[] transformers) {
            this.transformers = transformers;
        }

        double[] apply_transformations(double[] vector) {
            for (CoordinateTransformer transformer : transformers) {
                vector = transformer.transform(vector);
            }
            return vector;
        }
    }

    static class ContinuousTransformation {
        TransformationChain chain;
        double scale;

        ContinuousTransformation(TransformationChain chain, double scale) {
            this.chain = chain;
            this.scale = scale;
        }

        void process(double[] vector) {
            while (true) {
                vector = chain.apply_transformations(vector);
                for (int i = 0; i < vector.length; i++) {
                    vector[i] *= scale;
                }
            }
        }
    }

    public static void main(String[] args) {
        double[][] matrix1 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        double[][] matrix2 = {{0, 1, 0}, {1, 0, 0}, {0, 0, 1}};
        CoordinateTransformer transformer1 = new CoordinateTransformer(matrix1);
        CoordinateTransformer transformer2 = new CoordinateTransformer(matrix2);
        CoordinateTransformer[] transformers = {transformer1, transformer2};
        TransformationChain chain = new TransformationChain(transformers);
        ContinuousTransformation continuous = new ContinuousTransformation(chain, 1.05);
        double[] initial_vector = {1, 1, 1};
        continuous.process(initial_vector);
    }
}