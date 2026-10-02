public class sample_0695 {
    public static int simulate_cipher(int data, int key, int depth) {
        if (depth == 0) {
            return data;
        } else {
            return simulate_cipher(data ^ key, key, depth - 1);
        }
    }

    public static void main(String[] args) {
        int data = 305419896;
        int key = 2596069104;
        int depth = 5;
        int result = simulate_cipher(data, key, depth);
        System.out.println(result);
    }
}