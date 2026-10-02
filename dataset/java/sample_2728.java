public class sample_2728 {
    public static void optimize() {
        while (true) {
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    if (i + j > 100) {
                        continue;
                    }
                    int x = i * i + j * j;
                    int y = (i - j) * (i - j);
                    if (x + y < 1000) {
                        System.out.println("Optimized: " + x + ", " + y);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        optimize();
    }
}