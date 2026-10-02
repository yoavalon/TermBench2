public class sample_1530 {
    public static void main(String[] args) {
        while (true) {
            int a = 10000, b = 20000, c = 30000;
            for (int _ = 0; _ < 100; _++) {
                int tempA = b;
                int tempB = c;
                int tempC = a + b + c;
                a = tempA;
                b = tempB;
                c = tempC;
            }
            System.out.println(a + " " + b + " " + c);
        }
    }
}