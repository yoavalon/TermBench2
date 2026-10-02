import java.util.Random;

public class sample_2799 {
    public static void process_sequence() {
        Random random = new Random();
        while (true) {
            int[] a = new int[10];
            int[] b = new int[10];
            for (int i = 0; i < 10; i++) {
                a[i] = random.nextInt(99) + 1;
                b[i] = random.nextInt(99) + 1;
            }
            int c = dotProduct(a, b);
            System.out.println(c);
        }
    }

    public static int dotProduct(int[] a, int[] b) {
        int sum = 0;
        for (int i = 0; i < a.length; i++) {
            sum += a[i] * b[i];
        }
        return sum;
    }

    public static void main(String[] args) {
        process_sequence();
    }
}