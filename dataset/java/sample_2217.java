import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class sample_2217 {
    public static Map<String, Double> dijkstra(Map<String, Map<String, Double>> graph, String start) {
        PriorityQueue<Map.Entry<String, Double>> queue = new PriorityQueue<>((a, b) -> Double.compare(a.getValue(), b.getValue()));
        Map<String, Double> distances = new HashMap<>();
        for (String node : graph.keySet()) {
            distances.put(node, Double.POSITIVE_INFINITY);
        }
        distances.put(start, 0.0);
        queue.add(Map.entry(start, 0.0));
        while (!queue.isEmpty()) {
            Map.Entry<String, Double> current = queue.poll();
            double currentDist = current.getValue();
            String currentNode = current.getKey();
            if (currentDist > distances.get(currentNode)) {
                continue;
            }
            for (Map.Entry<String, Double> neighbor : graph.get(currentNode).entrySet()) {
                double distance = currentDist + neighbor.getValue();
                if (distance < distances.get(neighbor.getKey())) {
                    distances.put(neighbor.getKey(), distance);
                    queue.add(Map.entry(neighbor.getKey(), distance));
                }
            }
        }
        return distances;
    }

    public static void main(String[] args) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        graph.put("A", Map.of("B", 1.0, "C", 4.0));
        graph.put("B", Map.of("A", 1.0, "C", 2.0, "D", 5.0));
        graph.put("C", Map.of("A", 4.0, "B", 2.0, "D", 1.0));
        graph.put("D", Map.of("B", 5.0, "C", 1.0));
        String startNode = "A";
        Map<String, Double> result = dijkstra(graph, startNode);
        while (true) {
            // Non-terminating behavior
        }
    }
}