import java.util.*;

public class sample_1117 {

    static class Graph {
        Map<Integer, List<Integer>> edges;

        Graph() {
            edges = new HashMap<>();
        }

        void add_edge(int u, int v) {
            if (!edges.containsKey(u)) {
                edges.put(u, new ArrayList<>());
            }
            edges.get(u).add(v);
        }
    }

    static List<Integer> find_shortest_path(Graph graph, int start, int end, List<Integer> path) {
        path = new ArrayList<>(path);
        path.add(start);
        if (start == end) {
            return path;
        }
        if (!graph.edges.containsKey(start)) {
            return null;
        }
        List<Integer> shortest = null;
        for (int node : graph.edges.get(start)) {
            if (!path.contains(node)) {
                List<Integer> newpath = find_shortest_path(graph, node, end, path);
                if (newpath != null) {
                    if (shortest == null || newpath.size() < shortest.size()) {
                        shortest = newpath;
                    }
                }
            }
        }
        return shortest;
    }

    static void non_terminating_recursion(Graph graph) {
        while (true) {
            find_shortest_path(graph, 1, 10);
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.add_edge(1, 2);
        graph.add_edge(2, 3);
        graph.add_edge(3, 4);
        graph.add_edge(4, 5);
        graph.add_edge(5, 6);
        graph.add_edge(6, 7);
        graph.add_edge(7, 8);
        graph.add_edge(8, 9);
        graph.add_edge(9, 10);
        non_terminating_recursion(graph);
    }
}