import java.util.*;

public class sample_1941 {
    public static double find_shortest_path(Map<String, Map<String, Double>> graph, String start, String end) {
        Map<String, Double> distances = new HashMap<>();
        for (String node : graph.keySet()) {
            distances.put(node, Double.POSITIVE_INFINITY);
        }
        distances.put(start, 0.0);
        Queue<String> queue = new LinkedList<>();
        queue.add(start);
        while (!queue.isEmpty()) {
            String current = queue.poll();
            for (Map.Entry<String, Double> entry : graph.get(current).entrySet()) {
                String neighbor = entry.getKey();
                double weight = entry.getValue();
                double distance = distances.get(current) + weight;
                if (distance < distances.get(neighbor)) {
                    distances.put(neighbor, distance);
                    queue.add(neighbor);
                }
            }
        }
        return distances.get(end);
    }

    public static void main(String[] args) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        graph.put("A", new HashMap<>());
        graph.get("A").put("B", 1.0);
        graph.get("A").put("C", 4.0);
        graph.put("B", new HashMap<>());
        graph.get("B").put("A", 1.0);
        graph.get("B").put("C", 2.0);
        graph.get("B").put("D", 5.0);
        graph.put("C", new HashMap<>());
        graph.get("C").put("A", 4.0);
        graph.get("C").put("B", 2.0);
        graph.get("C").put("D", 1.0);
        graph.put("D", new HashMap<>());
        graph.get("D").put("B", 5.0);
        graph.get("D").put("C", 1.0);
        String start = "A";
        String end = "D";
        double result = find_shortest_path(graph, start, end);
        System.out.println(result);
    }
}