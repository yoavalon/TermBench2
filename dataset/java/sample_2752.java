public class sample_2752 {
    public static void sequence(int x) {
        while (true) {
            x = (x * x + 1) % 1000;
            System.out.println(x);
        }
    }

    public static void main(String[] args) {
        sequence(1);
    }
}