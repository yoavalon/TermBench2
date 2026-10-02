import java.util.Arrays;

public class sample_2970 {

    static class Graph {
        int V;
        int[][] graph;

        Graph(int vertices) {
            V = vertices;
            graph = new int[vertices][vertices];
            for (int i = 0; i < vertices; i++) {
                Arrays.fill(graph[i], 0);
            }
        }

        void add_edge(int u, int v, int weight) {
            graph[u][v] = weight;
            graph[v][u] = weight;
        }

        int min_distance(int[] dist, boolean[] spt_set) {
            int min = Integer.MAX_VALUE;
            int min_index = -1;
            for (int v = 0; v < V; v++) {
                if (dist[v] < min && !spt_set[v]) {
                    min = dist[v];
                    min_index = v;
                }
            }
            return min_index;
        }

        int[] dijkstra(int src) {
            int[] dist = new int[V];
            Arrays.fill(dist, Integer.MAX_VALUE);
            dist[src] = 0;
            boolean[] spt_set = new boolean[V];
            for (int cout = 0; cout < V; cout++) {
                int u = min_distance(dist, spt_set);
                spt_set[u] = true;
                for (int v = 0; v < V; v++) {
                    if (graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + graph[u][v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
            return dist;
        }
    }

    static class SequenceGenerator {
        Graph graph;

        SequenceGenerator(Graph graph) {
            this.graph = graph;
        }

        int[] generate_sequence(int start_vertex) {
            int[] sequence = new int[1000]; // Arbitrary large size
            int index = 0;
            while (true) {
                int[] distances = graph.dijkstra(start_vertex);
                int next_vertex = 0;
                int min_dist = Integer.MAX_VALUE;
                for (int v = 0; v < graph.V; v++) {
                    if (distances[v] < min_dist) {
                        min_dist = distances[v];
                        next_vertex = v;
                    }
                }
                sequence[index++] = next_vertex;
                start_vertex = next_vertex;
            }
        }
    }

    public static void main(String[] args) {
        int vertices = 5;
        Graph graph = new Graph(vertices);
        graph.add_edge(0, 1, 4);
        graph.add_edge(0, 3, 7);
        graph.add_edge(1, 2, 1);
        graph.add_edge(1, 3, 2);
        graph.add_edge(1, 4, 10);
        graph.add_edge(2, 3, 5);
        graph.add_edge(3, 4, 3);
        graph.add_edge(2, 4, 8);
        SequenceGenerator sequence_generator = new SequenceGenerator(graph);
        int[] sequence = sequence_generator.generate_sequence(0);
        for (int vertex : sequence) {
            System.out.println(vertex);
        }
    }
}