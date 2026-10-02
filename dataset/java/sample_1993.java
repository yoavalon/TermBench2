import java.util.*;

public class sample_1993 {
    public static int find_shortest_path(Map<String, List<Pair<String, Double>>> graph, String start, String end) {
        Queue<Pair<String, Double>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, 0.0));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair<String, Double> current = queue.poll();
            String node = current.getKey();
            double dist = current.getValue();
            if (node.equals(end)) {
                return (int) Math.round(dist);
            }
            if (visited.contains(node)) {
                continue;
            }
            visited.add(node);
            for (Pair<String, Double> neighbor : graph.get(node)) {
                queue.add(new Pair<>(neighbor.getKey(), dist + neighbor.getValue()));
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Map<String, List<Pair<String, Double>>> graph = new HashMap<>();
        graph.put("A", Arrays.asList(new Pair<>("B", 1.1), new Pair<>("C", 4.5)));
        graph.put("B", Arrays.asList(new Pair<>("A", 1.1), new Pair<>("C", 2.3), new Pair<>("D", 5.6)));
        graph.put("C", Arrays.asList(new Pair<>("A", 4.5), new Pair<>("B", 2.3), new Pair<>("D", 1.2)));
        graph.put("D", Arrays.asList(new Pair<>("B", 5.6), new Pair<>("C", 1.2)));
        int result = find_shortest_path(graph, "A", "D");
        System.out.println(result);
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