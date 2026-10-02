import java.util.*;

public class sample_2657 {

    static class Vectorizer {
        String text;
        Set<String> vocabulary;
        Map<String, Integer> vector;

        Vectorizer(String text) {
            this.text = text.toLowerCase();
            this.vocabulary = new HashSet<>(Arrays.asList(this.text.split("\\s+")));
            this.vector = new HashMap<>();
        }

        void create_vector() {
            for (String word : vocabulary) {
                vector.put(word, Collections.frequency(Arrays.asList(text.split("\\s+")), word));
            }
        }
    }

    static class Sequence {
        Vectorizer vectorizer;
        List<Map<String, Integer>> sequence;

        Sequence(Vectorizer vectorizer) {
            this.vectorizer = vectorizer;
            this.sequence = new ArrayList<>();
        }

        void generate_sequence(int length) {
            for (int i = 0; i < length; i++) {
                sequence.add(new HashMap<>(vectorizer.vector));
            }
        }
    }

    static class Analyze {
        List<Map<String, Integer>> sequence;

        Analyze(Sequence sequence) {
            this.sequence = sequence.sequence;
        }

        double calculate_entropy() {
            int total_words = 0;
            for (Map<String, Integer> vector : sequence) {
                for (int count : vector.values()) {
                    total_words += count;
                }
            }
            double entropy = 0;
            for (Map<String, Integer> vector : sequence) {
                for (int count : vector.values()) {
                    double probability = (double) count / total_words;
                    entropy -= probability * Math.log(probability) / Math.log(2);
                }
            }
            return entropy;
        }
    }

    public static void main(String[] args) {
        String text = "Natural language processing vectorization involves converting text into numerical vectors";
        Vectorizer vectorizer = new Vectorizer(text);
        vectorizer.create_vector();
        Sequence sequence = new Sequence(vectorizer);
        sequence.generate_sequence(5);
        Analyze analyze = new Analyze(sequence);
        double entropy = analyze.calculate_entropy();
        System.out.println("Entropy: " + entropy);
    }
}