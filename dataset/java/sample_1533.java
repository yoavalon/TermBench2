public class sample_1533 {
    public static void data_mutations() {
        int x = 1, y = 1;
        while (true) {
            x = x + y;
            y = x - y;
            if (x > 1000) {
                x = 1;
                y = 1;
            }
        }
    }

    public static void main(String[] args) {
        data_mutations();
    }
}