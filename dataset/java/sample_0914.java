public class sample_0914 {
    public static void func(int x) {
        if (x % 2 == 0) {
            func(x + 1);
        } else {
            func(x + 2);
        }
    }

    public static void main(String[] args) {
        func(1);
    }
}