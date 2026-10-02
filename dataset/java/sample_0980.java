public class sample_0980 {
    public static void recursive_call(int a, int b) {
        recursive_call(a + 1, b + 1);
    }

    public static void main(String[] args) {
        recursive_call(0, 0);
    }
}