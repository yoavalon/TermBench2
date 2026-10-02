import java.util.*;

class sample_1996 {
    static Map<String, Map<String, Double>> graph = new HashMap<>();
    static Map<String, Double> dist = new HashMap<>();
    static PriorityQueue<Map.Entry<String, Double>> priority_queue = new PriorityQueue<>((a, b) -> Double.compare(a.getValue(), b.getValue()));

    static Map<String, Double> dijkstra(Map<String, Map<String, Double>> graph, String start) {
        for (String node : graph.keySet()) {
            dist.put(node, Double.POSITIVE_INFINITY);
        }
        dist.put(start, 0.0);
        priority_queue.add(Map.entry(start, 0.0));

        while (!priority_queue.isEmpty()) {
            Map.Entry<String, Double> current = priority_queue.poll();
            String current_node = current.getKey();
            double current_dist = current.getValue();

            if (current_dist > dist.get(current_node)) {
                continue;
            }

            for (Map.Entry<String, Double> neighbor : graph.get(current_node).entrySet()) {
                double distance = current_dist + neighbor.getValue();
                if (distance < dist.get(neighbor.getKey())) {
                    dist.put(neighbor.getKey(), distance);
                    priority_queue.add(Map.entry(neighbor.getKey(), distance));
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        graph.put("A", Map.of("B", 1.1, "C", 4.2));
        graph.put("B", Map.of("A", 1.1, "C", 2.3, "D", 5.5));
        graph.put("C", Map.of("A", 4.2, "B", 2.3, "D", 1.0));
        graph.put("D", Map.of("B", 5.5, "C", 1.0));

        String start_node = "A";
        Map<String, Double> result = dijkstra(graph, start_node);
        System.out.println(result);
    }
}