public class sample_1518 {
    static void flight_planner() {
        int a = 10000, b = 20000, c = 30000;
        while (true) {
            int x = (a + b + c) / 3;
            a = b;
            b = c;
            c = x;
        }
    }

    public static void main(String[] args) {
        flight_planner();
    }
}