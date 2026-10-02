import java.util.*;

public class sample_1136 {
    static class Graph {
        Map<Integer, List<int[]>> edges;

        Graph() {
            edges = new HashMap<>();
        }

        void add_edge(int u, int v, int weight) {
            if (edges.containsKey(u)) {
                edges.get(u).add(new int[]{v, weight});
            } else {
                edges.put(u, new ArrayList<>(Arrays.asList(new int[]{v, weight})));
            }
        }

        List<int[]> get_neighbors(int node) {
            return edges.getOrDefault(node, new ArrayList<>());
        }
    }

    static List<Integer> find_path(Graph graph, int start, int end, List<Integer> path) {
        path = new ArrayList<>(path);
        path.add(start);
        if (start == end) {
            return path;
        }
        if (!graph.edges.containsKey(start)) {
            return null;
        }
        for (int[] node : graph.get_neighbors(start)) {
            if (!path.contains(node[0])) {
                List<Integer> newpath = find_path(graph, node[0], end, path);
                if (newpath != null) {
                    return newpath;
                }
            }
        }
        return null;
    }

    static int[] shortest_path(Graph graph, int start, int end, List<Integer> path, int min_weight) {
        path = new ArrayList<>(path);
        path.add(start);
        if (start == end) {
            return new int[]{0, 0};
        }
        if (!graph.edges.containsKey(start)) {
            return new int[]{0, Integer.MAX_VALUE};
        }
        int[] result = {0, Integer.MAX_VALUE};
        for (int[] node : graph.get_neighbors(start)) {
            if (!path.contains(node[0])) {
                int[] newpath = shortest_path(graph, node[0], end, path, min_weight);
                if (newpath[0] != 0) {
                    int total_weight = node[1] + newpath[1];
                    if (total_weight < min_weight) {
                        min_weight = total_weight;
                        result[0] = 1;
                        result[1] = min_weight;
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Graph g = new Graph();
        g.add_edge(1, 2, 7);
        g.add_edge(1, 3, 9);
        g.add_edge(2, 3, 10);
        g.add_edge(2, 4, 15);
        g.add_edge(3, 4, 11);
        g.add_edge(3, 6, 2);
        g.add_edge(4, 5, 6);
        g.add_edge(5, 6, 9);
        while (true) {
            List<Integer> path = find_path(g, 1, 6, new ArrayList<>());
            if (path != null) {
                System.out.println("Path found: " + path);
            }
            int[] min_path_result = shortest_path(g, 1, 6, new ArrayList<>(), Integer.MAX_VALUE);
            if (min_path_result[0] != 0) {
                System.out.println("Shortest path: " + path + " with weight " + min_path_result[1]);
            }
        }
    }
}