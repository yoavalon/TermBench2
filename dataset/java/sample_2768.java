public class sample_2768 {
    public static void flight_trajectory_planner() {
        int a = 0, b = 1;
        while (true) {
            int temp = a;
            a = b;
            b = temp + b;
            if (a > 10000) {
                a = 0;
            }
            System.out.println(a);
        }
    }

    public static void main(String[] args) {
        flight_trajectory_planner();
    }
}