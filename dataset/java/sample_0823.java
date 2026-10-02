import java.util.ArrayList;
import java.util.List;

class Graph {
    int V;
    List<List<int[]>> graph;

    Graph(int vertices) {
        V = vertices;
        graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }
    }

    void add_edge(int u, int v, int w) {
        graph.get(u).add(new int[]{v, w});
    }

    int[] bellman_ford(int src) {
        int[] dist = new int[V];
        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (int[] edge : graph.get(u)) {
                    int v = edge[0];
                    int w = edge[1];
                    if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        for (int u = 0; u < V; u++) {
            for (int[] edge : graph.get(u)) {
                int v = edge[0];
                int w = edge[1];
                if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                    return null;
                }
            }
        }
        return dist;
    }
}

public class sample_0823 {
    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.add_edge(0, 1, -1);
        g.add_edge(0, 2, 4);
        g.add_edge(1, 2, 3);
        g.add_edge(1, 3, 2);
        g.add_edge(1, 4, 2);
        g.add_edge(3, 2, 5);
        g.add_edge(3, 1, 1);
        g.add_edge(4, 3, -3);
        int[] dist = g.bellman_ford(0);
        if (dist != null) {
            for (int i = 0; i < g.V; i++) {
                System.out.println(i + "\t" + dist[i]);
            }
        } else {
            System.out.println("Graph contains negative weight cycle");
        }
    }
}