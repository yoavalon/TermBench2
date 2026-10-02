import java.util.*;

class Graph {
    int V;
    List<List<int[]>> graph;

    Graph(int vertices) {
        V = vertices;
        graph = new ArrayList<>(vertices);
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }
    }

    void add_edge(int u, int v, int weight) {
        graph.get(u).add(new int[]{v, weight});
        graph.get(v).add(new int[]{u, weight});
    }
}

class sample_0255 {
    static int[] dijkstra(Graph graph, int src) {
        int[] dist = new int[graph.V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0, src});
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int u_dist = current[0];
            int u = current[1];
            if (u_dist > dist[u]) {
                continue;
            }
            for (int[] edge : graph.graph.get(u)) {
                int v = edge[0];
                int weight = edge[1];
                int alt = u_dist + weight;
                if (alt < dist[v]) {
                    dist[v] = alt;
                    pq.add(new int[]{alt, v});
                }
            }
        }
        return dist;
    }

    static int find_shortest_path(Graph graph, int start, int end) {
        int[] distances = dijkstra(graph, start);
        return distances[end];
    }

    public static void main(String[] args) {
        int vertices = 5;
        Graph graph = new Graph(vertices);
        graph.add_edge(0, 1, 4);
        graph.add_edge(0, 7, 8);
        graph.add_edge(1, 2, 8);
        graph.add_edge(1, 7, 11);
        graph.add_edge(2, 3, 7);
        graph.add_edge(2, 5, 4);
        graph.add_edge(2, 8, 2);
        graph.add_edge(3, 4, 9);
        graph.add_edge(3, 5, 14);
        graph.add_edge(4, 5, 10);
        graph.add_edge(5, 6, 2);
        graph.add_edge(6, 7, 1);
        graph.add_edge(6, 8, 6);
        graph.add_edge(7, 8, 7);
        int start_node = 0;
        int end_node = 4;
        int shortest_path = find_shortest_path(graph, start_node, end_node);
        System.out.println("Shortest path from " + start_node + " to " + end_node + ": " + shortest_path);
    }
}