public class sample_0751 {
    public static int optimize_route(int[][] cost_matrix, int[] current_route, boolean[] visited, int total_cost) {
        if (current_route.length == cost_matrix.length) {
            return total_cost;
        }
        int min_cost = Integer.MAX_VALUE;
        for (int i = 0; i < cost_matrix.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                int cost = optimize_route(cost_matrix, appendToRoute(current_route, i), visited, total_cost + cost_matrix[current_route[current_route.length - 1]][i]);
                visited[i] = false;
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
        }
        return min_cost;
    }

    public static int[] appendToRoute(int[] current_route, int next_city) {
        int[] new_route = new int[current_route.length + 1];
        System.arraycopy(current_route, 0, new_route, 0, current_route.length);
        new_route[current_route.length] = next_city;
        return new_route;
    }

    public static void main(String[] args) {
        int[][] cost_matrix = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
        int[] initial_route = {0};
        boolean[] visited = new boolean[cost_matrix.length];
        visited[0] = true;
        int result = optimize_route(cost_matrix, initial_route, visited, 0);
        System.out.println(result);
    }
}