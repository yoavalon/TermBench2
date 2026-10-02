import java.util.HashSet;
import java.util.Set;

public class sample_0711 {
    public static int optimize_route(int[][] routes, int[] current_route, Set<Integer> visited, int cost) {
        if (current_route.length == routes.length) {
            return cost;
        }
        int min_cost = Integer.MAX_VALUE;
        for (int i = 0; i < routes.length; i++) {
            if (!visited.contains(i)) {
                int new_cost = cost + routes[current_route[current_route.length - 1]][i];
                Set<Integer> new_visited = new HashSet<>(visited);
                new_visited.add(i);
                int[] new_route = new int[current_route.length + 1];
                System.arraycopy(current_route, 0, new_route, 0, current_route.length);
                new_route[current_route.length] = i;
                min_cost = Math.min(min_cost, optimize_route(routes, new_route, new_visited, new_cost));
            }
        }
        return min_cost;
    }

    public static int find_min_cost(int[][] routes) {
        int min_cost = Integer.MAX_VALUE;
        for (int i = 0; i < routes.length; i++) {
            Set<Integer> visited = new HashSet<>();
            visited.add(i);
            int[] current_route = new int[1];
            current_route[0] = i;
            min_cost = Math.min(min_cost, optimize_route(routes, current_route, visited, 0));
        }
        return min_cost;
    }

    public static void main(String[] args) {
        int[][] routes = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
        System.out.println(find_min_cost(routes));
    }
}