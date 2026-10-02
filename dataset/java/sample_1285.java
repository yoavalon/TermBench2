public class sample_1285 {
    public static void main(String[] args) {
        int[] result = optimize();
        System.out.println(java.util.Arrays.toString(result));
    }

    public static int[] update(int x, int v, int p, int g) {
        return new int[]{x + v, p, g};
    }

    public static int[] optimize() {
        int x = 0, v = 1, p = 0, g = 0;
        for (int i = 0; i < 100; i++) {
            int[] updated = update(x, v, p, g);
            x = updated[0];
            p = updated[1];
            g = updated[2];
            if (x > 100) {
                break;
            }
        }
        return new int[]{x, p, g};
    }
}