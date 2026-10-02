public class sample_1871 {
    public static void main(String[] args) {
        double a = 1.0, b = 1.0, c = 0.0;
        for (int _ = 0; _ < 10; _++) {
            c = a + b;
            a = b;
            b = c;
        }
        System.out.println(c);
    }
}