import java.util.ArrayList;
import java.util.List;

public class sample_2670 {

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
            graph.get(v).add(new int[]{u, w});
        }
    }

    int min_distance(int[] dist, boolean[] sptSet) {
        int min = Integer.MAX_VALUE;
        int min_index = -1;
        for (int v = 0; v < dist.length; v++) {
            if (dist[v] < min && !sptSet[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    int[] dijkstra(Graph graph, int src) {
        int[] dist = new int[graph.V];
        for (int i = 0; i < graph.V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        boolean[] sptSet = new boolean[graph.V];
        for (int i = 0; i < graph.V; i++) {
            int u = min_distance(dist, sptSet);
            sptSet[u] = true;
            for (int[] neighbor : graph.graph.get(u)) {
                int v = neighbor[0];
                int weight = neighbor[1];
                if (!sptSet[v] && dist[u] != Integer.MAX_VALUE && (dist[u] + weight < dist[v])) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        sample_2670 s = new sample_2670();
        Graph g = s.new Graph(9);
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
        int[] dist = s.dijkstra(g, 0);
        for (int node = 0; node < dist.length; node++) {
            System.out.println("Distance to node " + node + " is " + dist[node]);
        }
    }
}