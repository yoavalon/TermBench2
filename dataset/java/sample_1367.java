import java.util.*;

public class sample_1367 {
    public static List<Object> dijkstra(Map<String, Map<String, Integer>> graph, String start, String end) {
        PriorityQueue<Object[]> queue = new PriorityQueue<>(Comparator.comparingInt(o -> (int) o[0]));
        queue.offer(new Object[]{0, start, new ArrayList<String>()});
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Object[] current = queue.poll();
            int cost = (int) current[0];
            String node = (String) current[1];
            List<String> path = (List<String>) current[2];
            if (!visited.contains(node)) {
                visited.add(node);
                path = new ArrayList<>(path);
                path.add(node);
                if (node.equals(end)) {
                    return Arrays.asList(path, cost);
                }
                Map<String, Integer> neighbors = graph.getOrDefault(node, Collections.emptyMap());
                for (Map.Entry<String, Integer> entry : neighbors.entrySet()) {
                    String neighbor = entry.getKey();
                    int neighborCost = entry.getValue();
                    if (!visited.contains(neighbor)) {
                        queue.offer(new Object[]{cost + neighborCost, neighbor, path});
                    }
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", Map.of("B", 1, "C", 4));
        graph.put("B", Map.of("A", 1, "C", 2, "D", 5));
        graph.put("C", Map.of("A", 4, "B", 2, "D", 1));
        graph.put("D", Map.of("B", 5, "C", 1));
        String startNode = "A";
        String endNode = "D";
        List<Object> result = dijkstra(graph, startNode, endNode);
        if (result != null) {
            List<String> path = (List<String>) result.get(0);
            int cost = (int) result.get(1);
            System.out.println("Path: " + path + ", Cost: " + cost);
        }
    }
}