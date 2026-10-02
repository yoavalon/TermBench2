public class sample_0930 {
    public static void non_terminating_recursion(int x, int y) {
        if (x > y) {
            non_terminating_recursion(y, x);
        } else {
            non_terminating_recursion(x + 1, y);
        }
    }

    public static void main(String[] args) {
        non_terminating_recursion(0, 1);
    }
}