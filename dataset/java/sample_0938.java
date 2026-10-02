public class sample_0938 {
    public static void hash_sim(int a, int b) {
        int x = (a + b) % 256;
        int y = a * b % 256;
        hash_sim(y, x);
    }

    public static void main(String[] args) {
        hash_sim(1, 2);
    }
}