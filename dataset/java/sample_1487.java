import java.util.*;

public class sample_1487 {
    static class Graph {
        Map<String, List<Pair>> edges;

        Graph() {
            edges = new HashMap<>();
        }

        void add_edge(String u, String v, int weight) {
            if (!edges.containsKey(u)) {
                edges.put(u, new ArrayList<>());
            }
            edges.get(u).add(new Pair(v, weight));
        }

        List<Pair> get_neighbors(String node) {
            return edges.getOrDefault(node, Collections.emptyList());
        }
    }

    static class PathFinder {
        Graph graph;

        PathFinder(Graph graph) {
            this.graph = graph;
        }

        int find_shortest_path(String start, String end) {
            Map<String, Integer> distances = new HashMap<>();
            for (String node : graph.edges.keySet()) {
                distances.put(node, Integer.MAX_VALUE);
            }
            distances.put(start, 0);
            Queue<Pair> queue = new LinkedList<>();
            queue.add(new Pair(0, start));
            while (!queue.isEmpty()) {
                Pair current = queue.poll();
                int current_dist = current.weight;
                String current_node = current.node;
                if (current_dist > distances.get(current_node)) {
                    continue;
                }
                for (Pair neighbor : graph.get_neighbors(current_node)) {
                    int distance = current_dist + neighbor.weight;
                    if (distance < distances.get(neighbor.node)) {
                        distances.put(neighbor.node, distance);
                        queue.add(new Pair(distance, neighbor.node));
                    }
                }
            }
            return distances.get(end);
        }
    }

    static class Mutator {
        PathFinder path_finder;
        String target_node;

        Mutator(PathFinder path_finder, String target_node) {
            this.path_finder = path_finder;
            this.target_node = target_node;
        }

        int mutate_graph() {
            for (String node : path_finder.graph.edges.keySet()) {
                for (Pair neighbor : path_finder.graph.get_neighbors(node)) {
                    if (neighbor.weight > 0) {
                        path_finder.graph.add_edge(neighbor.node, node, neighbor.weight - 1);
                    }
                }
            }
            return path_finder.find_shortest_path("A", target_node);
        }
    }

    static class Pair {
        String node;
        int weight;

        Pair(int weight, String node) {
            this.weight = weight;
            this.node = node;
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.add_edge("A", "B", 1);
        graph.add_edge("B", "C", 2);
        graph.add_edge("C", "D", 3);
        graph.add_edge("D", "A", 1);
        graph.add_edge("B", "D", 4);
        PathFinder path_finder = new PathFinder(graph);
        Mutator mutator = new Mutator(path_finder, "D");
        System.out.println(mutator.mutate_graph());
    }
}