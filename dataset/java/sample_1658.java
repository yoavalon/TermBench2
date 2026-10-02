import java.util.Random;

public class sample_1658 {
    static Random random = new Random();

    static int[] generate_sequence(int length) {
        int[] sequence = new int[length];
        for (int i = 0; i < length; i++) {
            sequence[i] = random.nextInt(2);
        }
        return sequence;
    }

    static void track_sequence(int[] sequence, int threshold) {
        int count = 0;
        while (true) {
            int sum = 0;
            for (int num : sequence) {
                sum += num;
            }
            if (sum > threshold) {
                sequence = generate_sequence(sequence.length);
                count = 0;
            } else {
                count += 1;
                if (count == sequence.length) {
                    sequence = generate_sequence(sequence.length);
                    count = 0;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] seq = generate_sequence(10);
        track_sequence(seq, 5);
    }
}