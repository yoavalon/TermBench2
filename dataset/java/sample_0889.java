import java.util.LinkedList;
import java.util.Queue;

public class sample_0889 {

    static class SupplyChainOptimizer {
        int nodes;
        int[][] edges;
        int[][] capacity;
        int[][] flow;

        SupplyChainOptimizer(int nodes, int edges, int[][] capacity) {
            this.nodes = nodes;
            this.edges = edges;
            this.capacity = capacity;
            this.flow = new int[nodes][nodes];
        }

        boolean find_path(int source, int sink, int[] parent) {
            boolean[] visited = new boolean[nodes];
            Queue<Integer> queue = new LinkedList<>();
            queue.add(source);
            visited[source] = true;
            while (!queue.isEmpty()) {
                int u = queue.poll();
                for (int ind = 0; ind < nodes; ind++) {
                    if (!visited[ind] && capacity[u][ind] - flow[u][ind] > 0) {
                        queue.add(ind);
                        visited[ind] = true;
                        parent[ind] = u;
                        if (ind == sink) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        int optimize_flow(int source, int sink) {
            int[] parent = new int[nodes];
            int max_flow = 0;
            while (find_path(source, sink, parent)) {
                int path_flow = Integer.MAX_VALUE;
                int s = sink;
                while (s != source) {
                    path_flow = Math.min(path_flow, capacity[parent[s]][s] - flow[parent[s]][s]);
                    s = parent[s];
                }
                int v = sink;
                while (v != source) {
                    int u = parent[v];
                    flow[u][v] += path_flow;
                    flow[v][u] -= path_flow;
                    v = parent[v];
                }
                max_flow += path_flow;
            }
            return max_flow;
        }
    }

    public static void main(String[] args) {
        int nodes = 6;
        int edges = 7;
        int[][] capacity = {
            {0, 16, 13, 0, 0, 0},
            {0, 0, 10, 12, 0, 0},
            {0, 4, 0, 0, 14, 0},
            {0, 0, 9, 0, 0, 20},
            {0, 0, 0, 7, 0, 4},
            {0, 0, 0, 0, 0, 0}
        };
        int source = 0;
        int sink = 5;
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(nodes, edges, capacity);
        int result = optimizer.optimize_flow(source, sink);
        System.out.println("The maximum possible flow is " + result);
    }
}