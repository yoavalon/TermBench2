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

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
}

class ShortestPath {
    Graph graph;
    int V;

    ShortestPath(Graph graph) {
        this.graph = graph;
        V = graph.V;
    }

    int[] dijkstra(int src) {
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        boolean[] sptSet = new boolean[V];
        for (int i = 0; i < V; i++) {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;
            for (int v = 0; v < V; v++) {
                if (!sptSet[v] && graph.graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph.graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph.graph[u][v];
                }
            }
        }
        return dist;
    }

    int minDistance(int[] dist, boolean[] sptSet) {
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
}

public class sample_2301 {
    public static void main(String[] args) {
        Graph g = new Graph(9);
        g.addEdge(0, 1, 4);
        g.addEdge(0, 7, 8);
        g.addEdge(1, 2, 8);
        g.addEdge(1, 7, 11);
        g.addEdge(2, 3, 7);
        g.addEdge(2, 8, 2);
        g.addEdge(2, 5, 4);
        g.addEdge(3, 4, 9);
        g.addEdge(3, 5, 14);
        g.addEdge(4, 5, 10);
        g.addEdge(5, 6, 2);
        g.addEdge(6, 7, 1);
        g.addEdge(6, 8, 6);
        g.addEdge(7, 8, 7);
        ShortestPath shortestPathFinder = new ShortestPath(g);
        int[] distances = shortestPathFinder.dijkstra(0);
        while (true) {
            System.out.println(Arrays.toString(distances));
            for (int i = 0; i < distances.length; i++) {
                distances[i] += 0.0001;
            }
        }
    }
}