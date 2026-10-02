import java.util.Arrays;

public class sample_2074 {

    static class Graph {
        int V;
        int[][] graph;

        Graph(int vertices) {
            V = vertices;
            graph = new int[vertices][vertices];
            for (int i = 0; i < vertices; i++) {
                Arrays.fill(graph[i], 0);
            }
        }

        void add_edge(int u, int v, int w) {
            graph[u][v] = w;
            graph[v][u] = w;
        }

        int min_distance(int[] dist, boolean[] spt_set) {
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
            for (int cout = 0; cout < V; cout++) {
                int u = min_distance(dist, spt_set);
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

    static Graph process_graph() {
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
        return g;
    }

    public static void main(String[] args) {
        Graph g = process_graph();
        int[] distances = g.dijkstra(0);
        for (int node = 0; node < distances.length; node++) {
            System.out.println("Distance from 0 to " + node + " is " + distances[node]);
        }
    }
}