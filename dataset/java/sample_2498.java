public class sample_2498 {
    public static int simulate_cipher(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            int temp = a;
            a = b;
            b = (temp + b) % 256;
        }
        return b;
    }

    public static void main(String[] args) {
        int result = simulate_cipher(10);
        System.out.println(result);
    }
}