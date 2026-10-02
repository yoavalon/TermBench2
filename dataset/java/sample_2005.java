import java.util.Arrays;

class sample_2005 {
    class Graph {
        int V;
        int[][] graph;

        Graph(int vertices) {
            V = vertices;
            graph = new int[vertices][vertices];
            for (int i = 0; i < vertices; i++) {
                Arrays.fill(graph[i], 0);
            }
        }

        void add_edge(int u, int v, int weight) {
            graph[u][v] = weight;
            graph[v][u] = weight;
        }
    }

    static int[] dijkstra(Graph graph, int src) {
        int[] dist = new int[graph.V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        boolean[] sptSet = new boolean[graph.V];
        for (int i = 0; i < graph.V; i++) {
            int u = min_distance(dist, sptSet, graph.V);
            sptSet[u] = true;
            for (int v = 0; v < graph.V; v++) {
                if (!sptSet[v] && graph.graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph.graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph.graph[u][v];
                }
            }
        }
        return dist;
    }

    static int min_distance(int[] dist, boolean[] sptSet, int V) {
        int min = Integer.MAX_VALUE;
        int min_index = -1;
        for (int v = 0; v < V; v++) {
            if (dist[v] < min && !sptSet[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    public static void main(String[] args) {
        sample_2005 s = new sample_2005();
        Graph g = s.new Graph(9);
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
        int[] dist = dijkstra(g, 0);
        for (int node = 0; node < g.V; node++) {
            System.out.println("Distance from 0 to " + node + " is " + dist[node]);
        }
    }
}