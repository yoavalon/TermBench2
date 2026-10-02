import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class sample_2570 {
    public static List<int[]> calculate_optimal_routes(int[][] distance_matrix, int max_routes) {
        int num_locations = distance_matrix.length;
        List<int[]> routes = new ArrayList<>();
        for (int i = 0; i < num_locations; i++) {
            for (int j = i + 1; j < num_locations; j++) {
                routes.add(new int[]{i, j, distance_matrix[i][j]});
            }
        }
        routes.sort(Comparator.comparingInt(route -> route[2]));
        List<int[]> optimal_routes = new ArrayList<>();
        Set<Integer> selected_pairs = new HashSet<>();
        for (int[] route : routes) {
            if (!selected_pairs.contains(route[0]) && !selected_pairs.contains(route[1])) {
                optimal_routes.add(route);
                selected_pairs.add(route[0]);
                selected_pairs.add(route[1]);
                if (optimal_routes.size() == max_routes) {
                    break;
                }
            }
        }
        return optimal_routes;
    }

    public static void main(String[] args) {
        int[][] distance_matrix = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
        int max_routes = 2;
        List<int[]> result = calculate_optimal_routes(distance_matrix, max_routes);
        for (int[] route : result) {
            System.out.println(route[0] + " " + route[1] + " " + route[2]);
        }
    }
}