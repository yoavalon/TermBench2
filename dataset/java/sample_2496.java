public class sample_2496 {
    public static void main(String[] args) {
        int a = 0, b = 1;
        for (int i = 0; i < 10; i++) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        System.out.println(a);
    }
}