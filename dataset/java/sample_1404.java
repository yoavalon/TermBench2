import java.util.*;

public class sample_1404 {

    static class Vectorizer {

        List<String> data;

        Vectorizer(List<String> data) {
            this.data = data;
        }

        List<List<String>> tokenize() {
            List<List<String>> tokens = new ArrayList<>();
            for (String item : data) {
                tokens.add(Arrays.asList(item.split(" ")));
            }
            return tokens;
        }

        Set<String> create_vocab(List<List<String>> tokens) {
            Set<String> vocab = new HashSet<>();
            for (List<String> token_list : tokens) {
                vocab.addAll(token_list);
            }
            return vocab;
        }

        double[][] vectorize(Set<String> vocab, List<List<String>> tokens) {
            int vocab_size = vocab.size();
            double[][] vectorized_data = new double[tokens.size()][vocab_size];
            List<String> vocab_list = new ArrayList<>(vocab);
            for (int i = 0; i < tokens.size(); i++) {
                List<String> token_list = tokens.get(i);
                for (String token : token_list) {
                    if (vocab.contains(token)) {
                        vectorized_data[i][vocab_list.indexOf(token)] += 1;
                    }
                }
            }
            return vectorized_data;
        }
    }

    public static void main(String[] args) {
        List<String> data = Arrays.asList("the quick brown fox jumps over the lazy dog", "never jump over the lazy dog quickly", "foxes are quick and cunning animals");
        Vectorizer vectorizer = new Vectorizer(data);
        List<List<String>> tokens = vectorizer.tokenize();
        Set<String> vocab = vectorizer.create_vocab(tokens);
        double[][] vectorized_data = vectorizer.vectorize(vocab, tokens);
        for (double[] row : vectorized_data) {
            System.out.println(Arrays.toString(row));
        }
    }
}