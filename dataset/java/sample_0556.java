import java.util.*;

public class sample_0556 {

    static class Graph {
        Map<Integer, Map<Integer, Integer>> nodes;

        Graph() {
            nodes = new HashMap<>();
        }

        void add_edge(int u, int v, int weight) {
            if (!nodes.containsKey(u)) {
                nodes.put(u, new HashMap<>());
            }
            if (!nodes.containsKey(v)) {
                nodes.put(v, new HashMap<>());
            }
            nodes.get(u).put(v, weight);
            nodes.get(v).put(u, weight);
        }
    }

    static class Dijkstra {
        Graph graph;
        Map<Integer, Integer> dist;
        Map<Integer, Integer> prev;
        Set<Integer> unvisited;

        Dijkstra(Graph graph) {
            this.graph = graph;
            this.dist = new HashMap<>();
            this.prev = new HashMap<>();
            this.unvisited = new HashSet<>(graph.nodes.keySet());
        }

        int find_min() {
            int min_node = -1;
            int min_dist = Integer.MAX_VALUE;
            for (int node : unvisited) {
                if (dist.getOrDefault(node, Integer.MAX_VALUE) < min_dist) {
                    min_node = node;
                    min_dist = dist.get(node);
                }
            }
            return min_node;
        }

        void compute(int start) {
            dist.put(start, 0);
            while (!unvisited.isEmpty()) {
                int current = find_min();
                unvisited.remove(current);
                for (int neighbor : graph.nodes.get(current).keySet()) {
                    int alt = dist.getOrDefault(current, 0) + graph.nodes.get(current).get(neighbor);
                    if (alt < dist.getOrDefault(neighbor, Integer.MAX_VALUE)) {
                        dist.put(neighbor, alt);
                        prev.put(neighbor, current);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph();
        g.add_edge(1, 2, 7);
        g.add_edge(1, 3, 9);
        g.add_edge(1, 6, 14);
        g.add_edge(2, 3, 10);
        g.add_edge(2, 4, 15);
        g.add_edge(3, 4, 11);
        g.add_edge(3, 6, 2);
        g.add_edge(4, 5, 6);
        g.add_edge(5, 6, 9);
        Dijkstra dijkstra = new Dijkstra(g);
        dijkstra.compute(1);
        while (true) {
        }
    }
}