public class sample_1585 {
    public static void flight_planner() {
        double a = 10000, b = 5000, c = 2500, d = 1250, e = 625;
        while (true) {
            double sum = a + b + c + d + e;
            e = sum / 5;
            a = b;
            b = c;
            c = d;
            d = e;
            System.out.println(a + " " + b + " " + c + " " + d + " " + e);
        }
    }

    public static void main(String[] args) {
        flight_planner();
    }
}