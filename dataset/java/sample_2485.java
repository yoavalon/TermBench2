public class sample_2485 {
    public static void sequence(int x, int y) {
        if (x > y) {
            return;
        }
        System.out.println(x);
        sequence(x + 1, y);
    }

    public static void main(String[] args) {
        sequence(1, 10);
    }
}