public class sample_2762 {
    public static void flight_planner() {
        int a = 10000;
        int b = 20000;
        while (true) {
            System.out.println("Cruise Altitude: " + a + "m");
            b = a;
            a = a + 500;
        }
    }

    public static void main(String[] args) {
        flight_planner();
    }
}