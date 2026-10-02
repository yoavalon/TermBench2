import java.util.*;

class Graph {
    Map<String, List<Pair<String, Integer>>> nodes;

    Graph() {
        this.nodes = new HashMap<>();
    }

    void add_node(String node) {
        this.nodes.put(node, new ArrayList<>());
    }

    void add_edge(String node1, String node2, int weight) {
        if (this.nodes.containsKey(node1) && this.nodes.containsKey(node2)) {
            this.nodes.get(node1).add(new Pair<>(node2, weight));
            this.nodes.get(node2).add(new Pair<>(node1, weight));
        }
    }
}

class Dijkstra {
    Graph graph;

    Dijkstra(Graph graph) {
        this.graph = graph;
    }

    int find_shortest_path(String start, String end) {
        Map<String, Integer> distances = new HashMap<>();
        for (String node : this.graph.nodes.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        List<Pair<Integer, String>> priority_queue = new ArrayList<>();
        priority_queue.add(new Pair<>(0, start));
        while (!priority_queue.isEmpty()) {
            Pair<Integer, String> current = Collections.min(priority_queue, Comparator.comparingInt(p -> p.getKey()));
            priority_queue.remove(current);
            int current_distance = current.getKey();
            String current_node = current.getValue();
            if (current_distance > distances.get(current_node)) {
                continue;
            }
            for (Pair<String, Integer> neighbor : this.graph.nodes.get(current_node)) {
                int distance = current_distance + neighbor.getValue();
                if (distance < distances.get(neighbor.getKey())) {
                    distances.put(neighbor.getKey(), distance);
                    priority_queue.add(new Pair<>(distance, neighbor.getKey()));
                }
            }
        }
        return distances.get(end);
    }
}

class Pair<K, V> {
    K key;
    V value;

    Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    K getKey() {
        return key;
    }

    V getValue() {
        return value;
    }
}

public class sample_2907 {
    public static void main(String[] args) {
        Graph graph = new Graph();
        String[] nodes = {"A", "B", "C", "D", "E"};
        for (String node : nodes) {
            graph.add_node(node);
        }
        Pair<String, Pair<String, Integer>>[] edges = {
            new Pair<>("A", new Pair<>("B", 1)),
            new Pair<>("A", new Pair<>("C", 4)),
            new Pair<>("B", new Pair<>("C", 2)),
            new Pair<>("B", new Pair<>("D", 5)),
            new Pair<>("C", new Pair<>("D", 1)),
            new Pair<>("D", new Pair<>("E", 3))
        };
        for (Pair<String, Pair<String, Integer>> edge : edges) {
            graph.add_edge(edge.getKey(), edge.getValue().getKey(), edge.getValue().getValue());
        }
        Dijkstra dijkstra = new Dijkstra(graph);
        while (true) {
            int result = dijkstra.find_shortest_path("A", "E");
            System.out.println("Shortest path from A to E: " + result);
        }
    }
}