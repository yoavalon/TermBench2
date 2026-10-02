import java.util.*;

public class sample_1985 {
    public static Map<String, Integer> dijkstra(Map<String, Map<String, Integer>> graph, String start) {
        Map<String, Integer> dist = new HashMap<>();
        for (String node : graph.keySet()) {
            dist.put(node, Integer.MAX_VALUE);
        }
        dist.put(start, 0);
        PriorityQueue<Map.Entry<String, Integer>> heap = new PriorityQueue<>(Comparator.comparingInt(Map.Entry::getValue));
        heap.add(new AbstractMap.SimpleEntry<>(start, 0));
        while (!heap.isEmpty()) {
            Map.Entry<String, Integer> entry = heap.poll();
            String current_node = entry.getKey();
            int current_dist = entry.getValue();
            if (current_dist > dist.get(current_node)) {
                continue;
            }
            for (Map.Entry<String, Integer> neighbor : graph.get(current_node).entrySet()) {
                int distance = current_dist + neighbor.getValue();
                if (distance < dist.get(neighbor.getKey())) {
                    dist.put(neighbor.getKey(), distance);
                    heap.add(new AbstractMap.SimpleEntry<>(neighbor.getKey(), distance));
                }
            }
        }
        return dist;
    }

    public static int findShortestPath(Map<String, Map<String, Integer>> graph, String start, String end) {
        Map<String, Integer> distances = dijkstra(graph, start);
        return distances.get(end);
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", new HashMap<>());
        graph.get("A").put("B", 1);
        graph.get("A").put("C", 4);
        graph.put("B", new HashMap<>());
        graph.get("B").put("A", 1);
        graph.get("B").put("C", 2);
        graph.get("B").put("D", 5);
        graph.put("C", new HashMap<>());
        graph.get("C").put("A", 4);
        graph.get("C").put("B", 2);
        graph.get("C").put("D", 1);
        graph.put("D", new HashMap<>());
        graph.get("D").put("B", 5);
        graph.get("D").put("C", 1);
        System.out.println(findShortestPath(graph, "A", "D"));
    }
}