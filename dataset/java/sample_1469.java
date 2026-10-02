public class sample_1469 {

    static class Graph {

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

        void add_edge(int u, int v, int weight) {
            this.graph[u][v] = weight;
            this.graph[v][u] = weight;
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
            for (int i = 0; i < V; i++) {
                dist[i] = Integer.MAX_VALUE;
            }
            dist[src] = 0;
            boolean[] spt_set = new boolean[V];
            for (int count = 0; count < V; count++) {
                int u = min_distance(dist, spt_set);
                spt_set[u] = true;
                for (int v = 0; v < V; v++) {
                    if (graph[u][v] != 0 && !spt_set[v] && dist[v] > dist[u] + graph[u][v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
            return dist;
        }
    }

    static class Router {

        Graph graph;

        Router(Graph graph) {
            this.graph = graph;
        }

        int[] find_shortest_paths(int start) {
            return graph.dijkstra(start);
        }
    }

    static class Network {

        Graph graph;
        Router router;

        Network(int vertices) {
            this.graph = new Graph(vertices);
            this.router = new Router(this.graph);
        }

        void connect_nodes(int u, int v, int weight) {
            this.graph.add_edge(u, v, weight);
        }

        int[] shortest_paths_from(int node) {
            return this.router.find_shortest_paths(node);
        }
    }

    public static void main(String[] args) {
        Network network = new Network(5);
        network.connect_nodes(0, 1, 10);
        network.connect_nodes(0, 3, 5);
        network.connect_nodes(1, 2, 1);
        network.connect_nodes(1, 3, 2);
        network.connect_nodes(1, 4, 3);
        network.connect_nodes(2, 4, 1);
        network.connect_nodes(3, 2, 4);
        network.connect_nodes(3, 4, 2);
        network.connect_nodes(4, 2, 6);
        network.connect_nodes(4, 0, 7);
        int[] paths = network.shortest_paths_from(0);
        for (int path : paths) {
            System.out.print(path + " ");
        }
    }
}