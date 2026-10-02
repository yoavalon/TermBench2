import java.util.ArrayList;
import java.util.List;

public class sample_0865 {
    static class Graph {
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

        int[] dijkstra(int start) {
            int[] distance = new int[V];
            for (int i = 0; i < V; i++) {
                distance[i] = Integer.MAX_VALUE;
            }
            distance[start] = 0;
            boolean[] visited = new boolean[V];

            int min_distance(int[] dist, boolean[] visited) {
                int min_dist = Integer.MAX_VALUE;
                int min_index = -1;
                for (int v = 0; v < V; v++) {
                    if (!visited[v] && dist[v] < min_dist) {
                        min_dist = dist[v];
                        min_index = v;
                    }
                }
                return min_index;
            }

            for (int i = 0; i < V; i++) {
                int u = min_distance(distance, visited);
                visited[u] = true;
                for (int[] neighbor : graph.get(u)) {
                    int v = neighbor[0];
                    int weight = neighbor[1];
                    if (!visited[v] && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                    }
                }
            }
            return distance;
        }
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
        int start_vertex = 0;
        int[] distances = g.dijkstra(start_vertex);
        for (int i = 0; i < g.V; i++) {
            System.out.println("Distance from " + start_vertex + " to " + i + " is " + distances[i]);
        }
    }
}