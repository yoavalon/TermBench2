import java.util.*;

public class sample_0202 {

    static class Vectorizer {

        String[] corpus;
        List<List<String>> tokenized;
        Map<String, Integer> vocabulary;
        double[][] vectorized;

        Vectorizer(String[] corpus) {
            this.corpus = corpus;
            this.tokenized = tokenize();
            this.vocabulary = build_vocabulary();
            this.vectorized = vectorize();
        }

        List<List<String>> tokenize() {
            List<List<String>> tokenized = new ArrayList<>();
            for (String doc : corpus) {
                tokenized.add(Arrays.asList(doc.toLowerCase().split("\\s+")));
            }
            return tokenized;
        }

        Map<String, Integer> build_vocabulary() {
            Set<String> vocab = new HashSet<>();
            for (List<String> doc : tokenized) {
                vocab.addAll(doc);
            }
            Map<String, Integer> vocabulary = new HashMap<>();
            int idx = 0;
            for (String word : vocab) {
                vocabulary.put(word, idx++);
            }
            return vocabulary;
        }

        double[][] vectorize() {
            double[][] vectors = new double[tokenized.size()][vocabulary.size()];
            for (int i = 0; i < tokenized.size(); i++) {
                List<String> doc = tokenized.get(i);
                for (String word : doc) {
                    if (vocabulary.containsKey(word)) {
                        vectors[i][vocabulary.get(word)] += 1;
                    }
                }
            }
            return vectors;
        }
    }

    static String[] load_data() {
        return new String[]{"This is a sample document", "Another document for testing", "Sample document number three"};
    }

    static double[][] analyze_vectors(double[][] vectors) {
        double[] average_vector = new double[vectors[0].length];
        double[] max_vector = new double[vectors[0].length];

        for (double[] vector : vectors) {
            for (int i = 0; i < vector.length; i++) {
                average_vector[i] += vector[i];
                if (vector[i] > max_vector[i]) {
                    max_vector[i] = vector[i];
                }
            }
        }

        for (int i = 0; i < average_vector.length; i++) {
            average_vector[i] /= vectors.length;
        }

        return new double[][]{average_vector, max_vector};
    }

    public static void main(String[] args) {
        String[] data = load_data();
        Vectorizer vectorizer = new Vectorizer(data);
        double[][] result = analyze_vectors(vectorizer.vectorized);
        System.out.println("Average Vector: " + Arrays.toString(result[0]));
        System.out.println("Maximum Vector: " + Arrays.toString(result[1]));
    }
}