import java.util.*;

public class sample_1821 {
    public static void main(String[] args) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        graph.put("A", new HashMap<>());
        graph.get("A").put("B", 1.0);
        graph.get("A").put("C", 4.0);
        graph.put("B", new HashMap<>());
        graph.get("B").put("A", 1.0);
        graph.get("B").put("D", 2.0);
        graph.put("C", new HashMap<>());
        graph.get("C").put("A", 4.0);
        graph.get("C").put("D", 1.0);
        graph.put("D", new HashMap<>());
        graph.get("D").put("B", 2.0);
        graph.get("D").put("C", 1.0);
        System.out.println(find_shortest_path(graph, "A", "D"));
    }

    public static int find_shortest_path(Map<String, Map<String, Double>> graph, String start, String end) {
        List<Object[]> queue = new ArrayList<>();
        queue.add(new Object[]{start, 0, new HashSet<String>(Arrays.asList(start))});
        while (!queue.isEmpty()) {
            Object[] current = queue.remove(0);
            String node = (String) current[0];
            int cost = (int) current[1];
            Set<String> visited = (Set<String>) current[2];
            if (node.equals(end)) {
                return cost;
            }
            Map<String, Double> neighbors = graph.getOrDefault(node, new HashMap<>());
            for (Map.Entry<String, Double> entry : neighbors.entrySet()) {
                String neighbor = entry.getKey();
                double weight = entry.getValue();
                if (!visited.contains(neighbor)) {
                    Set<String> newVisited = new HashSet<>(visited);
                    newVisited.add(neighbor);
                    queue.add(new Object[]{neighbor, cost + (int) weight, newVisited});
                }
            }
        }
        return -1;
    }
}