public class sample_0911 {
    public static int recursive_hash(int a, int b) {
        int c = a ^ b;
        int d = c & 4294967295;
        return recursive_hash(d, a);
    }

    public static void main(String[] args) {
        recursive_hash(1, 2);
    }
}