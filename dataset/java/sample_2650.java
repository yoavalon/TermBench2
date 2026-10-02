import java.util.*;

class Graph {
    private Map<String, List<Pair<String, Integer>>> nodes;

    public Graph() {
        nodes = new HashMap<>();
    }

    public void add_edge(String u, String v, int weight) {
        if (nodes.containsKey(u)) {
            nodes.get(u).add(new Pair<>(v, weight));
        } else {
            List<Pair<String, Integer>> edges = new ArrayList<>();
            edges.add(new Pair<>(v, weight));
            nodes.put(u, edges);
        }
    }

    public List<Pair<String, Integer>> get_neighbors(String node) {
        return nodes.getOrDefault(node, Collections.emptyList());
    }
}

class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}

public class sample_2650 {
    public static Pair<Integer, List<String>> dijkstra(Graph graph, String start, String end) {
        PriorityQueue<Triple> queue = new PriorityQueue<>(Comparator.comparingInt(t -> t.cost));
        queue.add(new Triple(0, start, new ArrayList<>()));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Triple triple = queue.poll();
            int cost = triple.cost;
            String node = triple.node;
            List<String> path = triple.path;
            if (!visited.contains(node)) {
                visited.add(node);
                path = new ArrayList<>(path);
                path.add(node);
                if (node.equals(end)) {
                    return new Pair<>(cost, path);
                }
                for (Pair<String, Integer> neighbor : graph.get_neighbors(node)) {
                    if (!visited.contains(neighbor.getKey())) {
                        queue.add(new Triple(cost + neighbor.getValue(), neighbor.getKey(), path));
                    }
                }
            }
        }
        return new Pair<>(Integer.MAX_VALUE, new ArrayList<>());
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.add_edge("A", "B", 1);
        graph.add_edge("A", "C", 4);
        graph.add_edge("B", "C", 2);
        graph.add_edge("B", "D", 5);
        graph.add_edge("C", "D", 1);
        Pair<Integer, List<String>> result = dijkstra(graph, "A", "D");
        System.out.println("Cost: " + result.getKey() + ", Path: " + result.getValue());
    }
}

class Triple {
    int cost;
    String node;
    List<String> path;

    public Triple(int cost, String node, List<String> path) {
        this.cost = cost;
        this.node = node;
        this.path = path;
    }
}