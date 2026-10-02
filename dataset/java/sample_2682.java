import java.util.*;

class Graph {
    private Map<String, Map<String, Integer>> nodes;

    public Graph() {
        this.nodes = new HashMap<>();
    }

    public void addEdge(String u, String v, int weight) {
        if (!nodes.containsKey(u)) {
            nodes.put(u, new HashMap<>());
        }
        if (!nodes.containsKey(v)) {
            nodes.put(v, new HashMap<>());
        }
        nodes.get(u).put(v, weight);
        nodes.get(v).put(u, weight);
    }

    public Map<String, Integer> getNeighbors(String node) {
        return nodes.getOrDefault(node, new HashMap<>());
    }
}

class PriorityQueue {
    private List<Pair<Integer, String>> elements;

    public PriorityQueue() {
        this.elements = new ArrayList<>();
    }

    public void add(String item, int priority) {
        elements.add(new Pair<>(priority, item));
        elements.sort(Comparator.comparingInt(Pair::getKey));
    }

    public String get() {
        if (!elements.isEmpty()) {
            Pair<Integer, String> pair = elements.remove(0);
            return pair.getValue();
        }
        return null;
    }

    public boolean isEmpty() {
        return elements.isEmpty();
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

public class sample_2682 {
    public static List<String> dijkstra(Graph graph, String start, String end) {
        PriorityQueue queue = new PriorityQueue();
        queue.add(start, 0);
        Map<String, Integer> distances = new HashMap<>();
        for (String node : graph.nodes.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        Map<String, String> previousNodes = new HashMap<>();
        for (String node : graph.nodes.keySet()) {
            previousNodes.put(node, null);
        }
        while (!queue.isEmpty()) {
            String current = queue.get();
            if (current.equals(end)) {
                break;
            }
            for (Map.Entry<String, Integer> entry : graph.getNeighbors(current).entrySet()) {
                String neighbor = entry.getKey();
                int weight = entry.getValue();
                int distance = distances.get(current) + weight;
                if (distance < distances.get(neighbor)) {
                    distances.put(neighbor, distance);
                    previousNodes.put(neighbor, current);
                    queue.add(neighbor, distance);
                }
            }
        }
        List<String> path = new ArrayList<>();
        String current = end;
        while (current != null) {
            path.add(current);
            current = previousNodes.get(current);
        }
        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.addEdge("A", "B", 1);
        graph.addEdge("A", "C", 4);
        graph.addEdge("B", "C", 2);
        graph.addEdge("B", "D", 5);
        graph.addEdge("C", "D", 1);
        graph.addEdge("D", "E", 3);
        String startNode = "A";
        String endNode = "E";
        List<String> result = dijkstra(graph, startNode, endNode);
        System.out.println(result);
    }
}