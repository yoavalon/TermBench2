public class sample_1264 {
    public static void flight_planner() {
        int[] data = {5000, 6000, 7000, 8000, 9000};
        int index = 0;
        while (index < data.length) {
            if (data[index] > 7500) {
                data[index] -= 500;
            }
            index += 1;
        }
    }

    public static void main(String[] args) {
        flight_planner();
    }
}