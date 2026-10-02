public class sample_0381 {
    public static void main(String[] args) {
        int x = 0;
        while (true) {
            x += 1;
            int y = x % 100;
            if (y == 0) {
                System.out.println(x);
            }
        }
    }
}