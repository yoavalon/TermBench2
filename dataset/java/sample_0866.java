public class sample_0866 {

    static class Graph {
        int v;
        int[][] graph;

        Graph(int vertices) {
            v = vertices;
            graph = new int[vertices][vertices];
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    graph[i][j] = 0;
                }
            }
        }

        void add_edge(int u, int v, int weight) {
            graph[u][v] = weight;
            graph[v][u] = weight;
        }
    }

    static int min_distance(int[] dist, boolean[] visited, int v) {
        int min_val = Integer.MAX_VALUE;
        int min_index = -1;
        for (int i = 0; i < v; i++) {
            if (dist[i] < min_val && !visited[i]) {
                min_val = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }

    static int[] dijkstra(int[][] graph, int src, int v) {
        int[] dist = new int[v];
        for (int i = 0; i < v; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        boolean[] visited = new boolean[v];
        for (int _ = 0; _ < v; _++) {
            int u = min_distance(dist, visited, v);
            visited[u] = true;
            for (int i = 0; i < v; i++) {
                if (graph[u][i] > 0 && !visited[i] && dist[u] + graph[u][i] < dist[i]) {
                    dist[i] = dist[u] + graph[u][i];
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        int v = 9;
        Graph g = new Graph(v);
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
        int[] dist = dijkstra(g.graph, 0, v);
        for (int node = 0; node < v; node++) {
            System.out.println("Distance to " + node + ": " + dist[node]);
        }
    }
}