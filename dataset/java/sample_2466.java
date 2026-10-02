public class sample_2466 {
    public static void main(String[] args) {
        System.out.println(generate_sequence(10));
    }

    public static double[] generate_sequence(int n) {
        double[] sequence = new double[n];
        sequence[0] = 1;
        for (int i = 1; i < n; i++) {
            sequence[i] = decay_reward(sequence[i - 1]);
        }
        return sequence;
    }

    public static double decay_reward(double x) {
        return x > 0 ? x * 0.95 : 0;
    }
}