import java.util.*;

public class sample_0261 {

    static class Vectorizer {

        List<String> data;
        int[][] vectorized_data;

        Vectorizer(List<String> data) {
            this.data = data;
            this.vectorized_data = null;
        }

        List<List<String>> preprocess() {
            List<List<String>> processed_data = new ArrayList<>();
            for (String item : data) {
                processed_data.add(Arrays.asList(item.toLowerCase().split(" ")));
            }
            return processed_data;
        }

        List<String> create_vocabulary(List<List<String>> processed_data) {
            Set<String> vocab = new HashSet<>();
            for (List<String> item : processed_data) {
                vocab.addAll(item);
            }
            return new ArrayList<>(vocab);
        }

        void vectorize(List<List<String>> processed_data, List<String> vocab) {
            vectorized_data = new int[processed_data.size()][vocab.size()];
            for (int i = 0; i < processed_data.size(); i++) {
                for (String word : processed_data.get(i)) {
                    vectorized_data[i][vocab.indexOf(word)] += 1;
                }
            }
        }

        int[][] get_vectorized_data() {
            return vectorized_data;
        }
    }

    static class Processor {

        Vectorizer vectorizer;

        Processor(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
        }

        void run_pipeline() {
            List<List<String>> processed_data = vectorizer.preprocess();
            List<String> vocab = vectorizer.create_vocabulary(processed_data);
            vectorizer.vectorize(processed_data, vocab);
        }
    }

    public static void main(String[] args) {
        List<String> data = Arrays.asList("The quick brown fox jumps over the lazy dog", "Never jump over a lazy dog quickly", "A quick brown dog outpaces a lazy fox");
        Vectorizer vectorizer = new Vectorizer(data);
        Processor processor = new Processor(vectorizer);
        processor.run_pipeline();
        int[][] vectorized_data = vectorizer.get_vectorized_data();
        for (int[] row : vectorized_data) {
            System.out.println(Arrays.toString(row));
        }
    }
}