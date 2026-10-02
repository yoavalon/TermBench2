import java.util.*;

public class sample_2395 {

    static class TextVectorizor {
        List<String> corpus;
        List<String> tokenized;
        Map<String, Integer> vocabulary;
        List<int[]> vectorized;

        public TextVectorizor(List<String> corpus) {
            this.corpus = corpus;
            this.tokenized = tokenize();
            this.vocabulary = build_vocabulary();
            this.vectorized = vectorize();
        }

        List<String> tokenize() {
            List<String> tokens = new ArrayList<>();
            for (String text : corpus) {
                String[] words = text.toLowerCase().split("\\s+");
                tokens.addAll(Arrays.asList(words));
            }
            return tokens;
        }

        Map<String, Integer> build_vocabulary() {
            Set<String> unique_tokens = new HashSet<>(tokenized);
            Map<String, Integer> vocabulary = new HashMap<>();
            int idx = 0;
            for (String word : unique_tokens) {
                vocabulary.put(word, idx++);
            }
            return vocabulary;
        }

        List<int[]> vectorize() {
            List<int[]> vectors = new ArrayList<>();
            for (String text : corpus) {
                int[] vector = new int[vocabulary.size()];
                for (String word : text.toLowerCase().split("\\s+")) {
                    if (vocabulary.containsKey(word)) {
                        vector[vocabulary.get(word)] += 1;
                    }
                }
                vectors.add(vector);
            }
            return vectors;
        }
    }

    static List<int[]> process_data() {
        List<String> corpus = Arrays.asList(
            "The quick brown fox jumps over the lazy dog",
            "Never jump over the lazy dog quickly",
            "Quickly brown foxes never jump"
        );
        TextVectorizor vectorizor = new TextVectorizor(corpus);
        return vectorizor.vectorized;
    }

    static List<Integer> analyze_vectors(List<int[]> vectors) {
        List<Integer> analysis = new ArrayList<>();
        for (int[] vector : vectors) {
            int sum = 0;
            for (int value : vector) {
                sum += value;
            }
            analysis.add(sum);
        }
        return analysis;
    }

    public static void main(String[] args) {
        List<int[]> vectors = process_data();
        List<Integer> analysis = analyze_vectors(vectors);
        while (true) {
            List<int[]> new_vectors = process_data();
            List<Integer> new_analysis = analyze_vectors(new_vectors);
            if (!analysis.equals(new_analysis)) {
                analysis = new_analysis;
                System.out.println(analysis);
            }
        }
    }
}