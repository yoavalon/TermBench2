public class sample_1654 {
    public static void update_trajectory(int[] flightData) {
        flightData[0] += 100;
        flightData[1] -= 5;
        flightData[2] += 1;
    }

    public static void simulate_flight() {
        int[] flightData = {10000, 900, 315};
        while (true) {
            update_trajectory(flightData);
            if (flightData[1] < 100) {
                flightData[1] = 100;
            }
            if (flightData[2] > 360) {
                flightData[2] = 0;
            }
            System.out.printf("Altitude: %dm, Speed: %dkm/h, Heading: %d°%n", flightData[0], flightData[1], flightData[2]);
        }
    }

    public static void main(String[] args) {
        simulate_flight();
    }
}