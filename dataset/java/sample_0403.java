import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;
import org.apache.commons.math3.ml.feature.Hasher;
import org.apache.commons.math3.ml.feature.TfidfTransformer;
import org.apache.commons.math3.ml.feature.Normalizer;
import org.apache.commons.math3.ml.feature.Hasher.HashingAlgorithm;

import java.util.ArrayList;
import java.util.List;

public class sample_0403 {

    public static RealMatrix preprocess_data(List<String> data) {
        Hasher hasher = new Hasher(1000, HashingAlgorithm.MURMURHASH3);
        Normalizer normalizer = new Normalizer();
        TfidfTransformer transformer = new TfidfTransformer();

        List<RealVector> vectors = new ArrayList<>();
        for (String sample : data) {
            RealVector vector = hasher.transform(sample);
            vectors.add(vector);
        }

        RealMatrix matrix = new Array2DRowRealMatrix(vectors.size(), hasher.getFeaturesCount());
        for (int i = 0; i < vectors.size(); i++) {
            matrix.setRowVector(i, vectors.get(i));
        }

        matrix = normalizer.transform(matrix);
        matrix = transformer.transform(matrix);
        return matrix;
    }

    public static void continuous_processing(RealMatrix X) {
        while (true) {
            double[][] transformedData = X.getData();
            for (int i = 0; i < transformedData.length; i++) {
                for (int j = 0; j < transformedData[i].length; j++) {
                    transformedData[i][j] = Math.log(transformedData[i][j] + 1);
                }
            }
            System.out.println(java.util.Arrays.deepToString(transformedData));
        }
    }

    public static void main(String[] args) {
        List<String> data_samples = List.of("Sample text data", "Another example", "NLP vectorization");
        RealMatrix X = preprocess_data(data_samples);
        continuous_processing(X);
    }
}