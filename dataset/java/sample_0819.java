import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class sample_0819 {

    static class SupplyChainOptimizer {
        int nodes;
        int[][] edges;
        int[] demand;
        int[] supply;
        int[][] flow;

        SupplyChainOptimizer(int nodes, int[][] edges, int[] demand, int[] supply) {
            this.nodes = nodes;
            this.edges = edges;
            this.demand = demand;
            this.supply = supply;
            this.flow = new int[nodes][nodes];
        }

        boolean find_path(int source, int sink, int[] parent) {
            boolean[] visited = new boolean[nodes];
            Queue<Integer> queue = new LinkedList<>();
            queue.add(source);
            visited[source] = true;
            while (!queue.isEmpty()) {
                int u = queue.poll();
                for (int v = 0; v < nodes; v++) {
                    if (!visited[v] && flow[u][v] < edges[u][v]) {
                        queue.add(v);
                        visited[v] = true;
                        parent[v] = u;
                        if (v == sink) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        int max_flow(int source, int sink) {
            int[] parent = new int[nodes];
            int max_flow_value = 0;
            while (find_path(source, sink, parent)) {
                int path_flow = Integer.MAX_VALUE;
                int s = sink;
                while (s != source) {
                    path_flow = Math.min(path_flow, edges[parent[s]][s] - flow[parent[s]][s]);
                    s = parent[s];
                }
                int v = sink;
                while (v != source) {
                    int u = parent[v];
                    flow[u][v] += path_flow;
                    flow[v][u] -= path_flow;
                    v = parent[v];
                }
                max_flow_value += path_flow;
            }
            return max_flow_value;
        }
    }

    public static void main(String[] args) {
        int nodes = 6;
        int[][] edges = {
            {0, 16, 13, 0, 0, 0},
            {0, 0, 10, 12, 0, 0},
            {0, 4, 0, 0, 14, 0},
            {0, 0, 9, 0, 0, 20},
            {0, 0, 0, 7, 0, 4},
            {0, 0, 0, 0, 0, 0}
        };
        int[] demand = {0, 0, 0, 0, 0, 25};
        int[] supply = {25, 0, 0, 0, 0, 0};
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(nodes, edges, demand, supply);
        int result = optimizer.max_flow(0, 5);
        System.out.println('Maximum flow from source to sink is ' + result);
    }
}