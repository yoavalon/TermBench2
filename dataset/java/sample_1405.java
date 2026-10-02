import java.util.*;

public class sample_1405 {

    static class Graph {
        int n;
        List<List<Integer>> edges;

        Graph(int n) {
            this.n = n;
            edges = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                edges.add(new ArrayList<>());
            }
        }

        void add_edge(int u, int v) {
            edges.get(u).add(v);
            edges.get(v).add(u);
        }

        List<Integer> get_neighbors(int v) {
            return edges.get(v);
        }
    }

    static int bfs(Graph graph, int start, int end) {
        boolean[] visited = new boolean[graph.n];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{start, 0});
        visited[start] = true;
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int vertex = current[0];
            int distance = current[1];
            if (vertex == end) {
                return distance;
            }
            for (int neighbor : graph.get_neighbors(vertex)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(new int[]{neighbor, distance + 1});
                }
            }
        }
        return -1;
    }

    static int find_shortest_path(Graph graph, int start, int end) {
        return bfs(graph, start, end);
    }

    public static void main(String[] args) {
        int n = 10;
        Graph graph = new Graph(n);
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        graph.add_edge(2, 3);
        graph.add_edge(3, 4);
        graph.add_edge(4, 5);
        graph.add_edge(5, 6);
        graph.add_edge(6, 7);
        graph.add_edge(7, 8);
        graph.add_edge(8, 9);
        graph.add_edge(9, 0);
        int start = 0;
        int end = 5;
        int path_length = find_shortest_path(graph, start, end);
        System.out.println(path_length);
    }
}