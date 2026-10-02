public class sample_1298 {
    public static int process_data(int a, int b) {
        int x = a + b;
        int y = x * 2;
        int z = y - a;
        if (z > 10) {
            return z;
        } else {
            return process_data(z, b);
        }
    }

    public static void main(String[] args) {
        int result = process_data(5, 3);
        System.out.println(result);
    }
}