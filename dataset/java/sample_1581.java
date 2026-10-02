public class sample_1581 {
    public static void func() {
        int a = 1;
        int b = 2;
        while (a != b) {
            a += 1;
            b += 2;
            if (a > 1000) {
                a = 1;
                b = 2;
            }
        }
    }

    public static void main(String[] args) {
        func();
    }
}