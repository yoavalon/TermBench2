import java.util.ArrayList;
import java.util.List;

public class sample_1422 {
    static class Graph {
        int V;
        List<int[]>[] graph;

        Graph(int vertices) {
            V = vertices;
            graph = new List[vertices];
            for (int i = 0; i < vertices; i++) {
                graph[i] = new ArrayList<>();
            }
        }

        void addEdge(int u, int v, int w) {
            graph[u].add(new int[]{v, w});
            graph[v].add(new int[]{u, w});
        }
    }

    static class ShortestPath {
        Graph graph;
        double[] dist;
        int[] parent;

        ShortestPath(Graph graph) {
            this.graph = graph;
            dist = new double[graph.V];
            parent = new int[graph.V];
            for (int i = 0; i < graph.V; i++) {
                dist[i] = Double.POSITIVE_INFINITY;
                parent[i] = -1;
            }
        }

        void bellmanFord(int src) {
            dist[src] = 0;
            for (int i = 0; i < graph.V - 1; i++) {
                for (int u = 0; u < graph.V; u++) {
                    for (int[] edge : graph.graph[u]) {
                        int v = edge[0];
                        int weight = edge[1];
                        if (dist[u] != Double.POSITIVE_INFINITY && dist[u] + weight < dist[v]) {
                            dist[v] = dist[u] + weight;
                            parent[v] = u;
                        }
                    }
                }
            }
        }

        List<Integer> getShortestPath(int dst) {
            List<Integer> path = new ArrayList<>();
            if (dist[dst] == Double.POSITIVE_INFINITY) {
                return path;
            }
            while (dst != -1) {
                path.add(dst);
                dst = parent[dst];
            }
            java.util.Collections.reverse(path);
            return path;
        }
    }

    public static void main(String[] args) {
        int V = 5;
        Graph graph = new Graph(V);
        graph.addEdge(0, 1, 4);
        graph.addEdge(0, 2, 8);
        graph.addEdge(1, 2, 8);
        graph.addEdge(1, 3, 7);
        graph.addEdge(1, 4, 9);
        graph.addEdge(2, 3, 4);
        graph.addEdge(2, 4, 2);
        graph.addEdge(3, 4, 11);
        graph.addEdge(3, 0, 2);
        graph.addEdge(4, 0, 7);
        ShortestPath shortestPathFinder = new ShortestPath(graph);
        shortestPathFinder.bellmanFord(0);
        List<Integer> path = shortestPathFinder.getShortestPath(4);
        System.out.println(path);
    }
}