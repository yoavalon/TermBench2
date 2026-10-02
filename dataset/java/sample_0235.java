import java.util.Arrays;

class Graph {
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

    int minDistance(int[] dist, boolean[] sptSet) {
        int minDist = Integer.MAX_VALUE;
        int minIndex = -1;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
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
                if (graph[u][v] > 0 && !sptSet[v] && dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        return dist;
    }
}

public class sample_0235 {
    static Graph constructGraph() {
        Graph g = new Graph(9);
        g.graph = new int[][]{
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}
        };
        return g;
    }

    public static void main(String[] args) {
        Graph graph = constructGraph();
        int[] distances = graph.dijkstra(0);
        System.out.println(Arrays.toString(distances));
    }
}