public class sample_1529 {
    public static void flight_planner() {
        int a = 1, b = 1, c = 0;
        while (true) {
            c = a + b;
            a = b;
            b = c;
            if (c > 30000) {
                a = 1;
                b = 1;
            }
        }
    }

    public static void main(String[] args) {
        flight_planner();
    }
}