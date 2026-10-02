import java.util.HashMap;
import java.util.Map;

public class sample_2584 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        sequence[0] = 0;
        sequence[1] = 1;
        for (int i = 2; i < n; i++) {
            sequence[i] = sequence[i - 1] + sequence[i - 2];
        }
        return sequence;
    }

    public static Map<String, Integer> vectorize_text(String text) {
        String[] words = text.split("\\s+");
        Map<String, Integer> word_count = new HashMap<>();
        for (String word : words) {
            word_count.put(word, word_count.getOrDefault(word, 0) + 1);
        }
        return word_count;
    }

    public static void main(String[] args) {
        int[] sequence = generate_sequence(10);
        String text = "hello world hello";
        Map<String, Integer> vector = vectorize_text(text);
        System.out.print(java.util.Arrays.toString(sequence) + " " + vector);
    }
}