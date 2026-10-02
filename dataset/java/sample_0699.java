public class sample_0699 {
    public static void simulate(int x, int y, int n) {
        if (n == 0) {
            System.out.println("(" + x + ", " + y + ")");
        } else {
            simulate(x + y, y, n - 1);
        }
    }

    public static void main(String[] args) {
        simulate(1, 1, 5);
    }
}