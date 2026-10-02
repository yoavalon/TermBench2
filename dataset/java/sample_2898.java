import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class sample_2898 {
    private static Random random = new Random();
    private static String alphabet = "abcdefghijklmnopqrstuvwxyz";

    public static void main(String[] args) {
        process_data();
    }

    public static char[] generate_sequence(int length) {
        char[] sequence = new char[length];
        for (int i = 0; i < length; i++) {
            sequence[i] = alphabet.charAt(random.nextInt(alphabet.length()));
        }
        return sequence;
    }

    public static Map<Character, Integer> vectorize_sequence(char[] sequence) {
        Map<Character, Integer> vector = new HashMap<>();
        for (char c : sequence) {
            vector.put(c, vector.getOrDefault(c, 0) + 1);
        }
        return vector;
    }

    public static void process_data() {
        while (true) {
            char[] seq = generate_sequence(100);
            Map<Character, Integer> vec = vectorize_sequence(seq);
            System.out.println(vec);
        }
    }
}