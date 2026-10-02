import java.util.*;

class Graph {
    int nodes;
    List<List<Integer>> edges;

    Graph(int n) {
        this.nodes = n;
        this.edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }
    }

    void connect(int u, int v) {
        edges.get(u).add(v);
        edges.get(v).add(u);
    }

    int find_shortest_paths(int start, int end) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{start, 0});
        boolean[] visited = new boolean[nodes];
        visited[start] = true;
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int node = current[0];
            int distance = current[1];
            if (node == end) {
                return distance;
            }
            for (int neighbor : edges.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(new int[]{neighbor, distance + 1});
                }
            }
        }
        return -1;
    }
}

Graph generate_sequence(int n) {
    Graph graph = new Graph(n);
    for (int i = 0; i < n; i++) {
        graph.connect(i, (i + 1) % n);
    }
    return graph;
}

public class sample_2664 {
    public static void main(String[] args) {
        int n = 10;
        Graph graph = generate_sequence(n);
        int start = 0;
        int end = 5;
        int result = graph.find_shortest_paths(start, end);
        System.out.println(result);
    }
}