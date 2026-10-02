public class sample_0875 {

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

        void addEdge(int u, int v, int weight) {
            graph[u][v] = weight;
            graph[v][u] = weight;
        }

        int minDistance(int dist[], boolean sptSet[]) {
            int min = Integer.MAX_VALUE, min_index = -1;
            for (int v = 0; v < V; v++) {
                if (dist[v] < min && !sptSet[v]) {
                    min = dist[v];
                    min_index = v;
                }
            }
            return min_index;
        }

        int[] dijkstra(int src) {
            int dist[] = new int[V];
            for (int i = 0; i < V; i++) {
                dist[i] = Integer.MAX_VALUE;
            }
            dist[src] = 0;
            boolean sptSet[] = new boolean[V];
            for (int count = 0; count < V; count++) {
                int u = minDistance(dist, sptSet);
                sptSet[u] = true;
                for (int v = 0; v < V; v++) {
                    if (!sptSet[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[v] > dist[u] + graph[u][v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
            return dist;
        }
    }

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
        int[] result = g.dijkstra(0);
        for (int i = 0; i < result.length; i++) {
            System.out.println("Vertex " + i + ": Distance from Source = " + result[i]);
        }
    }
}