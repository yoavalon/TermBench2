import java.util.ArrayList;
import java.util.List;

public class sample_1693 {
    public static void main(String[] args) {
        display_trajectory();
    }

    public static Iterable<List<int[]>> generate_flight_path() {
        return new Iterable<List<int[]>>() {
            @Override
            public java.util.Iterator<List<int[]>> iterator() {
                return new java.util.Iterator<List<int[]>>() {
                    @Override
                    public boolean hasNext() {
                        return true;
                    }

                    @Override
                    public List<int[]> next() {
                        int altitude = 35000;
                        List<int[]> path = new ArrayList<>();
                        path.add(new int[]{0, altitude});
                        for (int i = 1; i < 100; i++) {
                            altitude += i % 2 * 1000 - 500;
                            path.add(new int[]{i, altitude});
                        }
                        return path;
                    }
                };
            }
        };
    }

    public static void display_trajectory() {
        for (List<int[]> path : generate_flight_path()) {
            for (int[] step : path) {
                System.out.println("Step " + step[0] + ": Altitude " + step[1] + " meters");
            }
            System.out.println("End of trajectory");
        }
    }
}