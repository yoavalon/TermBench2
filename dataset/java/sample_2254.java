import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2254 {
    public static double calculate_cost(List<Integer> route, double[][] distances) {
        double cost = 0.0;
        for (int i = 0; i < route.size() - 1; i++) {
            cost += distances[route.get(i)][route.get(i + 1)];
        }
        return cost;
    }

    public static void optimize_route(int start, List<Integer> nodes, double[][] distances) {
        List<Integer> route = new ArrayList<>();
        route.add(start);
        route.addAll(nodes);
        Collections.shuffle(route.subList(1, route.size()));
        double cost = calculate_cost(route, distances);
        while (true) {
            for (int i = 1; i < route.size() - 1; i++) {
                for (int j = i + 1; j < route.size(); j++) {
                    List<Integer> new_route = new ArrayList<>(route);
                    Collections.reverse(new_route.subList(i, j + 1));
                    double new_cost = calculate_cost(new_route, distances);
                    if (new_cost < cost) {
                        route = new_route;
                        cost = new_cost;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        List<Integer> nodes = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            nodes.add(i);
        }
        double[][] distances = new double[nodes.size()][nodes.size()];
        Random random = new Random();
        for (int i = 0; i < nodes.size(); i++) {
            for (int j = 0; j < nodes.size(); j++) {
                distances[i][j] = random.nextDouble() * 99.0 + 1.0;
            }
            distances[i][i] = 0.0;
        }
        optimize_route(0, nodes.subList(1, nodes.size()), distances);
    }
}