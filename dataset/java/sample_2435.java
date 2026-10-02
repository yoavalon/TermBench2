public class sample_2435 {
    public static int f(int x) {
        int a = 0, b = 1, c = 1;
        for (int i = 0; i < x; i++) {
            int temp = a;
            a = b;
            b = c;
            c = temp + b + c;
        }
        return a;
    }

    public static void main(String[] args) {
        f(10);
    }
}