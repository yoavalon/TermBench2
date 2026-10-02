public class sample_0320 {
    public static void main(String[] args) {
        double x = 0;
        double decay_rate = 0.99;
        while (true) {
            x *= decay_rate;
            if (x < 0.01) {
                x = 1;
            }
            System.out.println(x);
        }
    }
}