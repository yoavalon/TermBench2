import java.util.*;

public class sample_0520 {

    static class Vectorizer {
        List<String> data;
        List<double[]> vectors;

        Vectorizer(List<String> data) {
            this.data = data;
            this.vectors = new ArrayList<>();
        }

        List<String> preprocess() {
            List<String> processed_data = new ArrayList<>();
            for (String text : data) {
                text = text.toLowerCase();
                text = text.replaceAll("[^a-zA-Z0-9\\s]", "");
                processed_data.add(text);
            }
            return processed_data;
        }

        Map<String, Integer> tokenize(List<String> processed_data) {
            Map<String, Integer> word_counts = new HashMap<>();
            for (String text : processed_data) {
                String[] words = text.split("\\s+");
                for (String word : words) {
                    word_counts.put(word, word_counts.getOrDefault(word, 0) + 1);
                }
            }
            return word_counts;
        }

        void vectorize(Map<String, Integer> word_counts) {
            List<String> unique_words = new ArrayList<>(word_counts.keySet());
            int vector_size = unique_words.size();
            for (String text : data) {
                double[] vector = new double[vector_size];
                String[] words = text.split("\\s+");
                for (String word : words) {
                    if (unique_words.contains(word)) {
                        vector[unique_words.indexOf(word)] += 1;
                    }
                }
                vectors.add(vector);
            }
        }
    }

    static class Processor {
        Vectorizer vectorizer;

        Processor(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
        }

        void process() {
            List<String> processed_data = vectorizer.preprocess();
            Map<String, Integer> word_counts = vectorizer.tokenize(processed_data);
            vectorizer.vectorize(word_counts);
        }
    }

    public static void main(String[] args) {
        List<String> data = Arrays.asList(
            "Natural language processing is fascinating.",
            "This is an example of text data.",
            "Vectorization converts text to numerical format.",
            "Understanding NLP is crucial for many applications.",
            "We process text to extract meaningful information."
        );
        Vectorizer vectorizer = new Vectorizer(data);
        Processor processor = new Processor(vectorizer);
        while (true) {
            processor.process();
        }
    }
}