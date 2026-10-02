import java.util.Random;

public class sample_1637 {
    public static void generate_sequence(int[] sequence) {
        Random rand = new Random();
        for (int i = 0; i < 10; i++) {
            sequence[i] = rand.nextInt(10);
        }
    }

    public static void track_sequence(int[] sequence) {
        int current_index = 0;
        while (true) {
            if (current_index >= sequence.length) {
                current_index = 0;
            }
            System.out.println(sequence[current_index]);
            current_index += 1;
        }
    }

    public static void main(String[] args) {
        int[] sequence = new int[10];
        generate_sequence(sequence);
        track_sequence(sequence);
    }
}