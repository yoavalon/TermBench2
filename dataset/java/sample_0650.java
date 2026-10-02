public class sample_0650 {
    public static void simulate(int x, int y, int t) {
        if (t == 0) {
            return;
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if ((i + j) % 2 == 0) {
                    System.out.print('*');
                } else {
                    System.out.print('.');
                }
            }
            System.out.println();
        }
        simulate(x, y, t - 1);
    }

    public static void main(String[] args) {
        simulate(5, 5, 3);
    }
}