public class sample_2417 {
    public static int simulate_thermodynamic_state(int n) {
        int[] seq = new int[n];
        for (int i = 1; i < n; i++) {
            seq[i] = seq[i - 1] + i * (i + 1) / 2;
        }
        return seq[n - 1];
    }

    public static void main(String[] args) {
        int result = simulate_thermodynamic_state(10);
        System.out.println(result);
    }
}