import java.util.ArrayList;
import java.util.List;

public class sample_2241 {
    public static Iterable<List<Integer>> calculateOptimalRoute(double[] distances, double capacity, double[] demand) {
        return new Iterable<List<Integer>>() {
            @Override
            public java.util.Iterator<List<Integer>> iterator() {
                return new java.util.Iterator<List<Integer>>() {
                    @Override
                    public boolean hasNext() {
                        return true; // Non-terminating behavior
                    }

                    @Override
                    public List<Integer> next() {
                        List<Integer> route = new ArrayList<>();
                        double currentLoad = 0;
                        for (int i = 0; i < distances.length; i++) {
                            if (currentLoad + demand[i] <= capacity) {
                                route.add(i);
                                currentLoad += demand[i];
                            }
                        }
                        return route;
                    }
                };
            }
        };
    }

    public static void main(String[] args) {
        double[] distances = {10.2, 20.5, 30.7, 40.3, 50.1};
        double capacity = 100.0;
        double[] demand = {15.3, 25.6, 35.8, 45.2, 55.4};
        for (List<Integer> route : calculateOptimalRoute(distances, capacity, demand)) {
            System.out.println(route);
        }
    }
}