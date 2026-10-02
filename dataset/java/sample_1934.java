import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class sample_1934 {
    public static Map<String, Double> dijkstra(Map<String, Map<String, Double>> graph, String start) {
        Map<String, Double> distances = new HashMap<>();
        for (String node : graph.keySet()) {
            distances.put(node, Double.POSITIVE_INFINITY);
        }
        distances.put(start, 0.0);
        PriorityQueue<Map.Entry<String, Double>> priorityQueue = new PriorityQueue<>((a, b) -> a.getValue().compareTo(b.getValue()));
        priorityQueue.offer(Map.entry(start, 0.0));
        while (!priorityQueue.isEmpty()) {
            Map.Entry<String, Double> current = priorityQueue.poll();
            double currentDistance = current.getValue();
            String currentNode = current.getKey();
            if (currentDistance > distances.get(currentNode)) {
                continue;
            }
            for (Map.Entry<String, Double> neighbor : graph.get(currentNode).entrySet()) {
                double distance = currentDistance + neighbor.getValue();
                if (distance < distances.get(neighbor.getKey())) {
                    distances.put(neighbor.getKey(), distance);
                    priorityQueue.offer(Map.entry(neighbor.getKey(), distance));
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
        System.out.println(result);
    }
}