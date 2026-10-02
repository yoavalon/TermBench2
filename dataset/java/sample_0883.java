public class sample_0883 {
    static class Graph {
        int V;
        int[][] graph;

        Graph(int vertices) {
            V = vertices;
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

    static void dijkstra(Graph graph, int src, int[] dist, boolean[] visited, int[] path) {
        if (all(visited)) {
            return;
        }
        int u = min(graph, visited, dist);
        visited[u] = true;
        for (int v = 0; v < graph.V; v++) {
            if (!visited[v] && graph.graph[u][v] != 0) {
                if (dist[u] + graph.graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph.graph[u][v];
                    path[v] = u;
                }
            }
        }
        dijkstra(graph, src, dist, visited, path);
    }

    static int min(Graph graph, boolean[] visited, int[] dist) {
        int min = Integer.MAX_VALUE;
        int min_index = -1;
        for (int v = 0; v < graph.V; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    static boolean all(boolean[] arr) {
        for (boolean b : arr) {
            if (!b) {
                return false;
            }
        }
        return true;
    }

    static int[] find_shortest_path(Graph graph, int src, int dest) {
        int[] dist = new int[graph.V];
        for (int i = 0; i < graph.V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        boolean[] visited = new boolean[graph.V];
        int[] path = new int[graph.V];
        for (int i = 0; i < graph.V; i++) {
            path[i] = -1;
        }
        dijkstra(graph, src, dist, visited, path);
        if (dist[dest] == Integer.MAX_VALUE) {
            return new int[0];
        }
        java.util.ArrayList<Integer> result = new java.util.ArrayList<>();
        while (dest != -1) {
            result.add(0, dest);
            dest = path[dest];
        }
        int[] resultArray = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            resultArray[i] = result.get(i);
        }
        return resultArray;
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
        int[] path = find_shortest_path(g, 0, 4);
        for (int v : path) {
            System.out.print(v + " ");
        }
    }
}