public class sample_0303 {
    public static void main(String[] args) {
        simulate();
    }

    public static void simulate() {
        int a = 1, b = 1, c = 0;
        while (true) {
            c = a + b;
            a = b;
            b = c;
            System.out.println(c);
        }
    }
}