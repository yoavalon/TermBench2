import java.util.*;

public class sample_0596 {

    static class Graph {
        Map<String, List<Pair>> nodes;

        public Graph() {
            nodes = new HashMap<>();
        }

        public void add_node(String node) {
            if (!nodes.containsKey(node)) {
                nodes.put(node, new ArrayList<>());
            }
        }

        public void add_edge(String node1, String node2, int weight) {
            if (nodes.containsKey(node1) && nodes.containsKey(node2)) {
                nodes.get(node1).add(new Pair(node2, weight));
                nodes.get(node2).add(new Pair(node1, weight));
            }
        }
    }

    static class Pair {
        String node;
        int weight;

        public Pair(String node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    static class Path {
        List<String> path;
        int cost;

        public Path(List<String> path, int cost) {
            this.path = path;
            this.cost = cost;
        }
    }

    public static Path dijkstra(Graph graph, String start, String goal) {
        PriorityQueue<Path> queue = new PriorityQueue<>(Comparator.comparingInt(p -> p.cost));
        queue.add(new Path(new ArrayList<>(), 0));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Path current = queue.poll();
            List<String> path = new ArrayList<>(current.path);
            String node = start;
            if (!path.isEmpty()) {
                node = path.get(path.size() - 1);
            }
            if (!visited.contains(node)) {
                visited.add(node);
                path.add(node);
                if (node.equals(goal)) {
                    return new Path(path, current.cost);
                }
                for (Pair neighbor : graph.nodes.get(node)) {
                    if (!visited.contains(neighbor.node)) {
                        queue.add(new Path(path, current.cost + neighbor.weight));
                    }
                }
            }
        }
        return new Path(new ArrayList<>(), Integer.MAX_VALUE);
    }

    public static void find_paths(Graph graph, String start, String goal) {
        List<Path> paths = new ArrayList<>();
        while (true) {
            Path path = dijkstra(graph, start, goal);
            if (!path.path.isEmpty()) {
                paths.add(path);
                graph.add_edge(path.path.get(path.path.size() - 1), path.path.get(path.path.size() - 1), 1);
            }
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.add_node("A");
        graph.add_node("B");
        graph.add_node("C");
        graph.add_node("D");
        graph.add_edge("A", "B", 1);
        graph.add_edge("B", "C", 2);
        graph.add_edge("C", "D", 3);
        graph.add_edge("D", "A", 4);
        find_paths(graph, "A", "D");
    }
}