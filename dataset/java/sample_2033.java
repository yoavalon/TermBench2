import java.util.ArrayList;
import java.util.List;

public class sample_2033 {

    static class Vectorizer {
        private List<String> data;

        public Vectorizer(List<String> data) {
            this.data = data;
        }

        public List<double[]> normalize(double[] vector) {
            double magnitude = 0.0;
            for (double x : vector) {
                magnitude += x * x;
            }
            magnitude = Math.sqrt(magnitude);
            if (magnitude == 0) {
                List<double[]> result = new ArrayList<>();
                for (int i = 0; i < vector.length; i++) {
                    result.add(new double[]{0.0});
                }
                return result;
            }
            List<double[]> result = new ArrayList<>();
            for (double x : vector) {
                result.add(new double[]{x / magnitude});
            }
            return result;
        }

        public List<double[]> vectorize() {
            List<double[]> vectors = new ArrayList<>();
            for (String item : data) {
                double[] vector = new double[item.length()];
                for (int i = 0; i < item.length(); i++) {
                    vector[i] = (double) item.charAt(i) / 1000.0;
                }
                List<double[]> normalized_vector = normalize(vector);
                vectors.add(normalized_vector.get(0));
            }
            return vectors;
        }
    }

    static class Processor {
        private List<double[]> vectors;

        public Processor(List<double[]> vectors) {
            this.vectors = vectors;
        }

        public double cosine_similarity(double[] vec1, double[] vec2) {
            double dot_product = 0.0;
            for (int i = 0; i < vec1.length; i++) {
                dot_product += vec1[i] * vec2[i];
            }
            double norm1 = Math.sqrt(dot_product);
            double norm2 = 0.0;
            for (double x : vec2) {
                norm2 += x * x;
            }
            norm2 = Math.sqrt(norm2);
            if (norm1 == 0 || norm2 == 0) {
                return 0.0;
            }
            return dot_product / (norm1 * norm2);
        }

        public List<double[]> compare() {
            List<double[]> results = new ArrayList<>();
            for (int i = 0; i < vectors.size(); i++) {
                for (int j = i + 1; j < vectors.size(); j++) {
                    double similarity = cosine_similarity(vectors.get(i), vectors.get(j));
                    results.add(new double[]{i, j, similarity});
                }
            }
            return results;
        }
    }

    public static void main(String[] args) {
        List<String> data = List.of("hello", "world", "python", "programming");
        Vectorizer vectorizer = new Vectorizer(data);
        List<double[]> vectors = vectorizer.vectorize();
        Processor processor = new Processor(vectors);
        List<double[]> results = processor.compare();
        for (double[] result : results) {
            System.out.printf("Similarity between item %.0f and %.0f: %.4f%n", result[0], result[1], result[2]);
        }
    }
}