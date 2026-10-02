public class sample_0349 {
    public static void main(String[] args) {
        int a = 1;
        int b = 1;
        while (true) {
            int c = a + b;
            a = b;
            b = c;
        }
    }
}