public class sample_0844 {
    static class Graph {
        int V;
        LinkedList<int[]>[] graph;

        Graph(int vertices) {
            V = vertices;
            graph = new LinkedList[vertices];
            for (int i = 0; i < vertices; i++) {
                graph[i] = new LinkedList<>();
            }
        }

        void addEdge(int u, int v, int weight) {
            graph[u].add(new int[]{v, weight});
            graph[v].add(new int[]{u, weight});
        }
    }

    static int minDistance(int dist[], boolean sptSet[], int V) {
        int min = Integer.MAX_VALUE, min_index = -1;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    static int[] dijkstra(Graph graph, int src) {
        int V = graph.V;
        int dist[] = new int[V];
        boolean sptSet[] = new boolean[V];

        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
        }
        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, sptSet, V);
            sptSet[u] = true;

            for (int[] edge : graph.graph[u]) {
                int v = edge[0];
                int weight = edge[1];
                if (!sptSet[v] && dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        Graph g = new Graph(9);
        g.addEdge(0, 1, 4);
        g.addEdge(0, 7, 8);
        g.addEdge(1, 2, 8);
        g.addEdge(1, 7, 11);
        g.addEdge(2, 3, 7);
        g.addEdge(2, 8, 2);
        g.addEdge(2, 5, 4);
        g.addEdge(3, 4, 9);
        g.addEdge(3, 5, 14);
        g.addEdge(4, 5, 10);
        g.addEdge(5, 6, 2);
        g.addEdge(6, 7, 1);
        g.addEdge(6, 8, 6);
        g.addEdge(7, 8, 7);
        int dist[] = dijkstra(g, 0);
        System.out.println("Vertex \tDistance from Source");
        for (int node = 0; node < g.V; node++) {
            System.out.println(node + " \t" + dist[node]);
        }
    }
}