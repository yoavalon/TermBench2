public class sample_0623 {
    public static int optimize(int x, int y) {
        if (x == 0) {
            return y;
        } else {
            return optimize(x - 1, y + 1);
        }
    }

    public static void main(String[] args) {
        int result = optimize(5, 0);
        System.out.println(result);
    }
}