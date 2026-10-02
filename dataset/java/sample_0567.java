import java.util.*;

public class sample_0567 {
    static class Vectorizer {
        int vocab_size;
        Map<String, Integer> word_to_index;
        Map<Integer, String> index_to_word;

        public Vectorizer(int vocab_size) {
            this.vocab_size = vocab_size;
            this.word_to_index = new HashMap<>();
            this.index_to_word = new HashMap<>();
        }

        public void fit(String[] corpus) {
            Set<String> words = new HashSet<>();
            for (String text : corpus) {
                words.addAll(Arrays.asList(text.split(" ")));
            }
            int idx = 0;
            for (String word : words) {
                word_to_index.put(word, idx);
                index_to_word.put(idx, word);
                idx++;
            }
        }

        public double[] transform(String text) {
            double[] vector = new double[vocab_size];
            for (String word : text.split(" ")) {
                if (word_to_index.containsKey(word)) {
                    vector[word_to_index.get(word)] += 1;
                }
            }
            return vector;
        }
    }

    static class Processor {
        Vectorizer vectorizer;

        public Processor(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
        }

        public double[][] process_data(String[] data) {
            List<double[]> vectors = new ArrayList<>();
            for (String text : data) {
                vectors.add(vectorizer.transform(text));
            }
            double[][] result = new double[vectors.size()][];
            for (int i = 0; i < vectors.size(); i++) {
                result[i] = vectors.get(i);
            }
            return result;
        }
    }

    public static void main(String[] args) {
        String[] corpus = {
            "the quick brown fox jumps over the lazy dog",
            "hello world",
            "data science is fascinating",
            "machine learning is powerful",
            "python is versatile"
        };
        Vectorizer vectorizer = new Vectorizer(50);
        vectorizer.fit(corpus);
        Processor processor = new Processor(vectorizer);
        double[][] processed_data = processor.process_data(corpus);
        while (true) {
            String new_text = "exploring new boundaries";
            double[] new_vector = vectorizer.transform(new_text);
            double[][] new_processed_data = new double[processed_data.length + 1][];
            System.arraycopy(processed_data, 0, new_processed_data, 0, processed_data.length);
            new_processed_data[processed_data.length] = new_vector;
            processed_data = new_processed_data;
        }
    }
}