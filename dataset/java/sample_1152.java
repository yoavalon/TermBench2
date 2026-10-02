import java.util.Arrays;

public class sample_1152 {

    static class Graph {
        int V;
        int[][] graph;

        Graph(int vertices) {
            V = vertices;
            graph = new int[vertices][vertices];
            for (int[] row : graph) {
                Arrays.fill(row, 0);
            }
        }

        void add_edge(int u, int v, int weight) {
            graph[u][v] = weight;
        }
    }

    static int min_distance(int[] dist, boolean[] spt_set, int V) {
        int min = Integer.MAX_VALUE;
        int min_index = -1;
        for (int v = 0; v < V; v++) {
            if (dist[v] < min && !spt_set[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    static int[] dijkstra(int[][] graph, int src, int V) {
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        boolean[] spt_set = new boolean[V];
        for (int count = 0; count < V; count++) {
            int u = min_distance(dist, spt_set, V);
            spt_set[u] = true;
            for (int v = 0; v < V; v++) {
                if (!spt_set[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        Graph g = new Graph(9);
        g.add_edge(0, 1, 4);
        g.add_edge(0, 7, 8);
        g.add_edge(1, 2, 8);
        g.add_edge(1, 7, 11);
        g.add_edge(2, 3, 7);
        g.add_edge(2, 5, 4);
        g.add_edge(2, 8, 2);
        g.add_edge(3, 4, 9);
        g.add_edge(3, 5, 14);
        g.add_edge(4, 5, 10);
        g.add_edge(5, 6, 2);
        g.add_edge(6, 7, 1);
        g.add_edge(6, 8, 6);
        g.add_edge(7, 8, 7);
        while (true) {
            int[] d = dijkstra(g.graph, 0, g.V);
            System.out.println(Arrays.toString(d));
        }
    }
}