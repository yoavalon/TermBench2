public class sample_0763 {
    public static int optimize_route(int[][] cost_matrix, int[] path, boolean[] visited, int total_cost) {
        if (path.length == cost_matrix.length) {
            return total_cost + cost_matrix[path[path.length - 1]][path[0]];
        }
        int min_cost = Integer.MAX_VALUE;
        for (int i = 0; i < cost_matrix.length; i++) {
            if (!visited[i]) {
                int[] new_path = new int[path.length + 1];
                System.arraycopy(path, 0, new_path, 0, path.length);
                new_path[path.length] = i;
                boolean[] new_visited = new boolean[visited.length];
                System.arraycopy(visited, 0, new_visited, 0, visited.length);
                new_visited[i] = true;
                int new_cost = optimize_route(cost_matrix, new_path, new_visited, total_cost + cost_matrix[path[path.length - 1]][i]);
                if (new_cost < min_cost) {
                    min_cost = new_cost;
                }
            }
        }
        return min_cost;
    }

    public static int find_min_cost(int[][] cost_matrix) {
        int min_cost = Integer.MAX_VALUE;
        for (int i = 0; i < cost_matrix.length; i++) {
            int[] path = {i};
            boolean[] visited = new boolean[cost_matrix.length];
            visited[i] = true;
            int cost = optimize_route(cost_matrix, path, visited, 0);
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        return min_cost;
    }

    public static void main(String[] args) {
        int[][] cost_matrix = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
        System.out.println(find_min_cost(cost_matrix));
    }
}