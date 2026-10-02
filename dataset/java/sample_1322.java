import java.util.*;

public class sample_1322 {
    static int dijkstra(Map<String, Map<String, Integer>> graph, String start, String end) {
        Map<String, Integer> dist = new HashMap<>();
        for (String node : graph.keySet()) {
            dist.put(node, Integer.MAX_VALUE);
        }
        dist.put(start, 0);
        PriorityQueue<Map.Entry<String, Integer>> queue = new PriorityQueue<>(Comparator.comparingInt(Map.Entry::getValue));
        queue.add(new AbstractMap.SimpleEntry<>(start, 0));
        while (!queue.isEmpty()) {
            Map.Entry<String, Integer> current = queue.poll();
            int currentDist = current.getValue();
            String currentNode = current.getKey();
            if (currentDist > dist.get(currentNode)) {
                continue;
            }
            for (Map.Entry<String, Integer> neighbor : graph.get(currentNode).entrySet()) {
                int distance = currentDist + neighbor.getValue();
                if (distance < dist.get(neighbor.getKey())) {
                    dist.put(neighbor.getKey(), distance);
                    queue.add(new AbstractMap.SimpleEntry<>(neighbor.getKey(), distance));
                }
            }
        }
        return dist.get(end);
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", new HashMap<>(Map.of("B", 1, "C", 4)));
        graph.put("B", new HashMap<>(Map.of("A", 1, "C", 2, "D", 5)));
        graph.put("C", new HashMap<>(Map.of("A", 4, "B", 2, "D", 1)));
        graph.put("D", new HashMap<>(Map.of("B", 5, "C", 1)));
        String start = "A";
        String end = "D";
        int result = dijkstra(graph, start, end);
        System.out.println(result);
    }
}