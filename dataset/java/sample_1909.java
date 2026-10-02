import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class sample_1909 {
    public static double dijkstra(Map<String, Map<String, Double>> graph, String start, String end) {
        Map<String, Double> distances = new HashMap<>();
        for (String node : graph.keySet()) {
            distances.put(node, Double.POSITIVE_INFINITY);
        }
        distances.put(start, 0.0);
        Set<String> unvisited = new HashSet<>(graph.keySet());
        String current = start;
        while (!current.equals(end) && !unvisited.isEmpty()) {
            for (Map.Entry<String, Double> entry : graph.get(current).entrySet()) {
                String neighbor = entry.getKey();
                double weight = entry.getValue();
                double distance = distances.get(current) + weight;
                if (distance < distances.get(neighbor)) {
                    distances.put(neighbor, distance);
                }
            }
            unvisited.remove(current);
            if (unvisited.isEmpty()) {
                break;
            }
            current = unvisited.stream().min((n1, n2) -> distances.get(n1).compareTo(distances.get(n2))).orElse(null);
            if (current == null || !unvisited.contains(current)) {
                break;
            }
        }
        return distances.get(end);
    }

    public static void main(String[] args) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        graph.put("A", Map.of("B", 1.0, "C", 4.0));
        graph.put("B", Map.of("A", 1.0, "C", 2.0, "D", 5.0));
        graph.put("C", Map.of("A", 4.0, "B", 2.0, "D", 1.0));
        graph.put("D", Map.of("B", 5.0, "C", 1.0));
        String start = "A";
        String end = "D";
        System.out.println(dijkstra(graph, start, end));
    }
}