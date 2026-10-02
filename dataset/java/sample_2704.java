public class sample_2704 {
    public static void main(String[] args) {
        process_data();
    }

    public static void process_data() {
        int x = 1;
        while (true) {
            x += 1;
            if (x % 2 == 0) {
                System.out.println(x);
            } else {
                System.out.println(x * x);
            }
        }
    }
}