public class sample_0813 {
    class Graph {
        int V;
        int[][] graph;

        Graph(int vertices) {
            this.V = vertices;
            this.graph = new int[vertices][vertices];
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    graph[i][j] = 0;
                }
            }
        }

        void add_edge(int u, int v, int w) {
            graph[u][v] = w;
            graph[v][u] = w;
        }

        void print_solution(int[] dist) {
            System.out.println("Vertex \t Distance from Source");
            for (int node = 0; node < V; node++) {
                System.out.println(node + " \t " + dist[node]);
            }
        }

        int min_distance(int[] dist, boolean[] spt_set) {
            int min = Integer.MAX_VALUE;
            int min_index = -1;
            for (int v = 0; v < V; v++) {
                if (!spt_set[v] && dist[v] <= min) {
                    min = dist[v];
                    min_index = v;
                }
            }
            return min_index;
        }

        void dijkstra(int src) {
            int[] dist = new int[V];
            boolean[] spt_set = new boolean[V];
            for (int i = 0; i < V; i++) {
                dist[i] = Integer.MAX_VALUE;
                spt_set[i] = false;
            }
            dist[src] = 0;
            for (int count = 0; count < V - 1; count++) {
                int u = min_distance(dist, spt_set);
                spt_set[u] = true;
                for (int v = 0; v < V; v++) {
                    if (!spt_set[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[v] > dist[u] + graph[u][v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
            print_solution(dist);
        }
    }

    public static void main(String[] args) {
        sample_0813 s = new sample_0813();
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
        g.dijkstra(0);
    }
}