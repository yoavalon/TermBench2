public class sample_0346 {
    public static void main(String[] args) {
        int a = 0, b = 1, c = 2;
        while (true) {
            int tempA = b;
            int tempB = c;
            int tempC = a + b + c;
            a = tempA;
            b = tempB;
            c = tempC;
        }
    }
}