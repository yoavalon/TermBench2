public class sample_2642 {
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

        int min_distance(int[] dist, boolean[] spt_set) {
            int min = Integer.MAX_VALUE;
            int min_index = -1;
            for (int v = 0; v < V; v++) {
                if (dist[v] < min && spt_set[v] == false) {
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
            for (int cout = 0; cout < V; cout++) {
                int u = min_distance(dist, spt_set);
                spt_set[u] = true;
                for (int v = 0; v < V; v++) {
                    if (graph[u][v] != 0 && spt_set[v] == false && dist[v] > dist[u] + graph[u][v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
            return dist;
        }
    }

    static class Sequence {
        Graph graph;
        int start;

        Sequence(Graph graph, int start) {
            this.graph = graph;
            this.start = start;
        }

        int[] generate_sequence() {
            int[] dist = graph.dijkstra(start);
            int[] sequence = new int[dist.length - 1];
            int index = 0;
            for (int i = 0; i < dist.length; i++) {
                if (i != start) {
                    sequence[index++] = dist[i];
                }
            }
            return sequence;
        }
    }

    public static void main(String[] args) {
        int V = 9;
        Graph g = new Graph(V);
        g.graph = new int[][] {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}
        };
        Sequence seq = new Sequence(g, 0);
        int[] result = seq.generate_sequence();
        for (int i : result) {
            System.out.print(i + " ");
        }
    }
}