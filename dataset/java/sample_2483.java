public class sample_2483 {
    public static int sequence(int a, int b, int n) {
        for (int i = 0; i < n; i++) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        System.out.println(sequence(0, 1, 10));
    }
}