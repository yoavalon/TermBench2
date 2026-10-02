import java.util.*;

class Graph {
    List<String> nodes;
    Map<String, List<Pair<String, Integer>>> edges;

    Graph(List<String> nodes) {
        this.nodes = nodes;
        this.edges = new HashMap<>();
    }

    void add_edge(String u, String v, int weight) {
        if (edges.containsKey(u)) {
            edges.get(u).add(new Pair<>(v, weight));
        } else {
            edges.put(u, new ArrayList<>(List.of(new Pair<>(v, weight))));
        }
        if (edges.containsKey(v)) {
            edges.get(v).add(new Pair<>(u, weight));
        } else {
            edges.put(v, new ArrayList<>(List.of(new Pair<>(u, weight))));
        }
    }
}

class PriorityQueue {
    List<Pair<Integer, String>> elements;

    PriorityQueue() {
        this.elements = new ArrayList<>();
    }

    void add(String item, int priority) {
        elements.add(new Pair<>(priority, item));
        Collections.sort(elements, Comparator.comparingInt(Pair::getKey));
    }

    String remove() {
        return elements.remove(0).getValue();
    }

    boolean empty() {
        return elements.isEmpty();
    }
}

class Pair<K, V> {
    private final K key;
    private final V value;

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

class sample_0217 {
    static Pair<Map<String, String>, Map<String, Integer>> dijkstra(Graph graph, String start, String end) {
        PriorityQueue queue = new PriorityQueue();
        queue.add(start, 0);
        Map<String, String> came_from = new HashMap<>();
        Map<String, Integer> cost_so_far = new HashMap<>();
        cost_so_far.put(start, 0);
        while (!queue.empty()) {
            String current = queue.remove();
            if (current.equals(end)) {
                break;
            }
            for (Pair<String, Integer> neighbor : graph.edges.getOrDefault(current, Collections.emptyList())) {
                int new_cost = cost_so_far.get(current) + neighbor.getValue();
                if (!cost_so_far.containsKey(neighbor.getKey()) || new_cost < cost_so_far.get(neighbor.getKey())) {
                    cost_so_far.put(neighbor.getKey(), new_cost);
                    int priority = new_cost;
                    queue.add(neighbor.getKey(), priority);
                    came_from.put(neighbor.getKey(), current);
                }
            }
        }
        return new Pair<>(came_from, cost_so_far);
    }

    static List<String> reconstruct_path(Map<String, String> came_from, String start, String end) {
        List<String> path = new ArrayList<>();
        String current = end;
        while (!current.equals(start)) {
            path.add(current);
            current = came_from.get(current);
        }
        path.add(start);
        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args) {
        List<String> nodes = Arrays.asList("A", "B", "C", "D", "E");
        Graph graph = new Graph(nodes);
        graph.add_edge("A", "B", 1);
        graph.add_edge("B", "C", 2);
        graph.add_edge("C", "D", 1);
        graph.add_edge("D", "E", 3);
        graph.add_edge("A", "E", 10);
        String start = "A";
        String end = "E";
        Pair<Map<String, String>, Map<String, Integer>> result = dijkstra(graph, start, end);
        List<String> path = reconstruct_path(result.getKey(), start, end);
        System.out.println("Shortest path from " + start + " to " + end + ": " + path);
        System.out.println("Cost of the path: " + result.getValue().get(end));
    }
}