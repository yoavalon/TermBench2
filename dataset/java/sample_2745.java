public class sample_2745 {
    public static void process_data() {
        while (true) {
            int[] a = new int[1000];
            for (int i = 0; i < 1000; i++) {
                a[i] = i * i;
            }
            int[] b = new int[1000];
            for (int i = 0; i < 1000; i++) {
                b[i] = a[i] + i;
            }
            int[] c = new int[1000];
            for (int i = 0; i < 1000; i++) {
                c[i] = b[i] * 2;
            }
        }
    }

    public static void main(String[] args) {
        process_data();
    }
}