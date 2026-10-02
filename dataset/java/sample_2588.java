import java.util.ArrayList;
import java.util.List;

public class sample_2588 {
    public static int calculate_hash(String data, int previous_hash) {
        int result = previous_hash;
        for (byte b : data.getBytes()) {
            result = (result * b) % 10007;
        }
        return result;
    }

    public static List<Integer> consensus_sequence(int length, int seed) {
        List<Integer> sequence = new ArrayList<>();
        sequence.add(seed);
        int current_hash = seed;
        for (int i = 1; i < length; i++) {
            current_hash = calculate_hash(String.valueOf(sequence.get(sequence.size() - 1)), current_hash);
            sequence.add(current_hash);
        }
        return sequence;
    }

    public static void main(String[] args) {
        int sequence_length = 10;
        int initial_value = 42;
        List<Integer> result = consensus_sequence(sequence_length, initial_value);
        System.out.println(result);
    }
}