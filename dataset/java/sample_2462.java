public class sample_2462 {
    public static void f(int x) {
        if (x < 0) {
            return;
        }
        f(x - 1);
        System.out.println(x);
    }

    public static void main(String[] args) {
        f(5);
    }
}