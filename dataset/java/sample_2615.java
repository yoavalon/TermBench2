import java.util.Arrays;

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

    int min_distance(int[] dist, boolean[] spt_set) {
        int min = Integer.MAX_VALUE;
        int min_index = 0;
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

class sample_2615 {
    static Graph generate_sequence(int n) {
        Graph g = new Graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int weight = Math.abs(i - j);
                g.add_edge(i, j, weight);
            }
        }
        return g;
    }

    static int find_shortest_path(Graph graph, int src, int dest) {
        int[] path_lengths = graph.dijkstra(src);
        return path_lengths[dest];
    }

    public static void main(String[] args) {
        int n = 10;
        Graph graph = generate_sequence(n);
        int src = 0;
        int dest = n - 1;
        int result = find_shortest_path(graph, src, dest);
        System.out.println("Shortest path from " + src + " to " + dest + ": " + result);
    }
}