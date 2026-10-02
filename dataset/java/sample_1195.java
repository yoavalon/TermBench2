import java.util.ArrayList;
import java.util.List;

class Graph {
    int V;
    List<int[]>[] graph;

    Graph(int vertices) {
        V = vertices;
        graph = new ArrayList[vertices];
        for (int i = 0; i < vertices; i++) {
            graph[i] = new ArrayList<>();
        }
    }

    void add_edge(int u, int v, int w) {
        graph[u].add(new int[]{v, w});
        graph[v].add(new int[]{u, w});
    }

    int[] dijkstra(int src) {
        int[] dist = new int[V];
        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        boolean[] visited = new boolean[V];
        while (true) {
            int min_dist = Integer.MAX_VALUE;
            int u = -1;
            for (int i = 0; i < V; i++) {
                if (!visited[i] && dist[i] < min_dist) {
                    min_dist = dist[i];
                    u = i;
                }
            }
            if (u == -1) {
                break;
            }
            visited[u] = true;
            for (int[] edge : graph[u]) {
                int v = edge[0];
                int weight = edge[1];
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }
}

public class sample_1195 {
    static void non_terminating_graph_traversal() {
        Graph g = new Graph(10);
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
        while (true) {
            int[] dist = g.dijkstra(0);
            for (int d : dist) {
                System.out.print(d + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        non_terminating_graph_traversal();
    }
}