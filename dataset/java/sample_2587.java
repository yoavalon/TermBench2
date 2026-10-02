import java.util.HashMap;
import java.util.Map;

public class sample_2587 {

    public static String[] tokenize(String text) {
        return text.toLowerCase().split("\\s+");
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

    public static int[] process_text(String text) {
        Map<String, Integer> vocab = new HashMap<>();
        vocab.put("hello", 0);
        vocab.put("world", 1);
        vocab.put("python", 2);
        String[] tokens = tokenize(text);
        return vectorize(tokens, vocab);
    }

    public static void main(String[] args) {
        String text = "Hello world, hello Python!";
        int[] result = process_text(text);
        for (int value : result) {
            System.out.print(value + " ");
        }
    }
}