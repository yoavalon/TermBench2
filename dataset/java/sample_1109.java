import java.util.Arrays;

class Graph {

    int V;
    int[][] graph;

    Graph(int vertices) {
        this.V = vertices;
        this.graph = new int[vertices][vertices];
        for (int[] row : graph) {
            Arrays.fill(row, 0);
        }
    }

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int find_min(int[] dist, boolean[] spt_set) {
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

    int[] dijkstra(int src) {
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        boolean[] spt_set = new boolean[V];
        for (int i = 0; i < V; i++) {
            int u = find_min(dist, spt_set);
            spt_set[u] = true;
            for (int v = 0; v < V; v++) {
                if (graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        return dist;
    }
}

public class sample_1109 {
    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.add_edge(0, 1, 1);
        g.add_edge(0, 2, 4);
        g.add_edge(1, 2, 4);
        g.add_edge(1, 3, 2);
        g.add_edge(1, 4, 7);
        g.add_edge(2, 3, 3);
        g.add_edge(2, 4, 5);
        g.add_edge(3, 4, 1);
        int[] dist = g.dijkstra(0);
        for (int node = 0; node < g.V; node++) {
            System.out.println("Distance from source to " + node + " is " + dist[node]);
        }
        while (true) {
        }
    }
}