public class sample_2749 {
    public static void main(String[] args) {
        while (true) {
            int f(int x) {
                if (x == 0) {
                    return 1;
                } else {
                    return x * f(x - 1);
                }
            }
            System.out.println(f(5));
        }
    }
}