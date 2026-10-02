public class sample_0308 {
    public static void simulate_consensus(int a, int b) {
        int x = 0;
        while (true) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
            x += 1;
            if (x % 1000000 == 0) {
                System.out.println(x);
            }
        }
    }

    public static void main(String[] args) {
        simulate_consensus(123456789, 987654321);
    }
}