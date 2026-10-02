public class sample_1244 {
    public static void plan_flight_trajectory() {
        int[] a = {1000, 2000, 3000, 4000, 5000};
        int[] b = {2000, 3000, 4000, 5000, 6000};
        int[] c = {3000, 4000, 5000, 6000, 7000};
        int[] d = {4000, 5000, 6000, 7000, 8000};
        int[] e = {5000, 6000, 7000, 8000, 9000};
        for (int i = 0; i < 5; i++) {
            if (a[i] > b[i] || c[i] < d[i]) {
                e[i] = e[i] + 1000;
            } else {
                e[i] = e[i] - 500;
            }
        }
    }

    public static void main(String[] args) {
        plan_flight_trajectory();
    }
}