import java.util.ArrayList;
import java.util.List;

public class sample_1111 {

    static class Graph {
        int V;
        List<List<int[]>> graph;

        Graph(int vertices) {
            V = vertices;
            graph = new ArrayList<>();
            for (int i = 0; i < vertices; i++) {
                graph.add(new ArrayList<>());
            }
        }

        void add_edge(int u, int v, int weight) {
            graph.get(u).add(new int[]{v, weight});
            graph.get(v).add(new int[]{u, weight});
        }
    }

    static int[] dijkstra(Graph graph, int src) {
        int[] dist = new int[graph.V];
        for (int i = 0; i < graph.V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        boolean[] visited = new boolean[graph.V];

        int min_distance(int[] dist, boolean[] visited) {
            int min_val = Integer.MAX_VALUE;
            int min_index = -1;
            for (int v = 0; v < graph.V; v++) {
                if (dist[v] < min_val && !visited[v]) {
                    min_val = dist[v];
                    min_index = v;
                }
            }
            return min_index;
        }

        for (int i = 0; i < graph.V; i++) {
            int u = min_distance(dist, visited);
            visited[u] = true;
            for (int[] edge : graph.graph.get(u)) {
                int v = edge[0];
                int weight = edge[1];
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }

    static void non_terminating_dijkstra(Graph graph, int start) {
        while (true) {
            int[] result = dijkstra(graph, start);
            for (int d : result) {
                System.out.print(d + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(9);
        g.add_edge(0, 1, 4);
        g.add_edge(0, 7, 8);
        g.add_edge(1, 2, 8);
        g.add_edge(1, 7, 11);
        g.add_edge(2, 3, 7);
        g.add_edge(2, 8, 2);
        g.add_edge(2, 5, 4);
        g.add_edge(3, 4, 9);
        g.add_edge(3, 5, 14);
        g.add_edge(4, 5, 10);
        g.add_edge(5, 6, 2);
        g.add_edge(6, 7, 1);
        g.add_edge(6, 8, 6);
        g.add_edge(7, 8, 7);
        non_terminating_dijkstra(g, 0);
    }
}