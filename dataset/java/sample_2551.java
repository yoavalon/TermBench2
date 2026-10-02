import java.util.Random;

public class sample_2551 {
    public static double[] generate_sequence(int length) {
        double[] sequence = new double[length];
        for (int i = 1; i < length; i++) {
            sequence[i] = sequence[i - 1] + new Random().nextInt(4) + 1;
        }
        return sequence;
    }

    public static double[] vectorize_sequence(double[] sequence) {
        for (int i = 0; i < sequence.length; i++) {
            sequence[i] = sequence[i] * 2;
        }
        return sequence;
    }

    public static void main(String[] args) {
        int seq_length = 10;
        double[] seq = generate_sequence(seq_length);
        double[] vec_seq = vectorize_sequence(seq);
        for (double value : vec_seq) {
            System.out.print(value + " ");
        }
    }
}