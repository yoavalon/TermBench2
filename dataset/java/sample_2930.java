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

    void add_edge(int u, int v, int weight) {
        graph.get(u).add(new int[]{v, weight});
        graph.get(v).add(new int[]{u, weight});
    }
}

class Dijkstra {
    Graph graph;

    Dijkstra(Graph graph) {
        this.graph = graph;
    }

    int min_distance(int[] dist, boolean[] spt_set) {
        int min = Integer.MAX_VALUE;
        int min_index = -1;
        for (int v = 0; v < graph.V; v++) {
            if (dist[v] < min && !spt_set[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    int[] dijkstra(int src) {
        int[] dist = new int[graph.V];
        for (int i = 0; i < graph.V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        boolean[] spt_set = new boolean[graph.V];
        for (int cout = 0; cout < graph.V; cout++) {
            int u = min_distance(dist, spt_set);
            spt_set[u] = true;
            for (int[] neighbor : graph.graph.get(u)) {
                int v = neighbor[0];
                int weight = neighbor[1];
                if (!spt_set[v] && dist[u] != Integer.MAX_VALUE && (dist[u] + weight < dist[v])) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }
}

public class sample_2930 {
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
        Dijkstra dijkstra = new Dijkstra(g);
        int[] result = dijkstra.dijkstra(0);
        while (true) {
        }
    }
}