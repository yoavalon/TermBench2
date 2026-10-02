import java.util.HashMap;
import java.util.Map;

public class sample_2504 {
    public static String[] tokenize(String text) {
        String[] words = text.toLowerCase().split("\\s+");
        return words;
    }

    public static int[] vectorize(String[] tokens, Map<String, Integer> vocab) {
        int[] vector = new int[vocab.size()];
        for (String token : tokens) {
            if (vocab.containsKey(token)) {
                vector[vocab.get(token)] += 1;
            }
        }
        return vector;
    }

    public static void main(String[] args) {
        String text = "hello world hello";
        Map<String, Integer> vocab = new HashMap<>();
        vocab.put("hello", 0);
        vocab.put("world", 1);
        String[] tokens = tokenize(text);
        int[] vector = vectorize(tokens, vocab);
        for (int v : vector) {
            System.out.print(v + " ");
        }
    }
}