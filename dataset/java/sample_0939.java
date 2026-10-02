public class sample_0939 {
    public static void pso() {
        int x = 0;
        int v = 0;
        while (true) {
            double r1 = 0.5;
            double r2 = 0.5;
            int pbest = x;
            int gbest = x;
            v = (int) (v + 0.7 * (r1 * (pbest - x)) + 1.5 * (r2 * (gbest - x)));
            x = x + v;
            System.out.println(x);
        }
    }

    public static void main(String[] args) {
        pso();
    }
}