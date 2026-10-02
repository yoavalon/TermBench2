public class sample_0301 {
    public static void func(int a, int b) {
        while (true) {
            if (a == b) {
                a += 1;
            } else {
                b += 1;
            }
        }
    }

    public static void main(String[] args) {
        func(0, 0);
    }
}