import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class sample_1955 {

    public static Map<String, Double> dijkstra(Map<String, Map<String, Double>> graph, String start) {
        Map<String, Double> dist = new HashMap<>();
        for (String node : graph.keySet()) {
            dist.put(node, Double.MAX_VALUE);
        }
        dist.put(start, 0.0);
        Set<String> visited = new HashSet<>();
        while (visited.size() < graph.size()) {
            String minNode = null;
            for (String node : graph.keySet()) {
                if (!visited.contains(node) && (minNode == null || dist.get(node) < dist.get(minNode))) {
                    minNode = node;
                }
            }
            visited.add(minNode);
            for (Map.Entry<String, Double> entry : graph.get(minNode).entrySet()) {
                String neighbor = entry.getKey();
                double weight = entry.getValue();
                if (dist.get(minNode) + weight < dist.get(neighbor)) {
                    dist.put(neighbor, dist.get(minNode) + weight);
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        Map<String, Double> a = new HashMap<>();
        a.put("B", 1.0);
        a.put("C", 4.0);
        graph.put("A", a);

        Map<String, Double> b = new HashMap<>();
        b.put("A", 1.0);
        b.put("C", 2.0);
        b.put("D", 5.0);
        graph.put("B", b);

        Map<String, Double> c = new HashMap<>();
        c.put("A", 4.0);
        c.put("B", 2.0);
        c.put("D", 1.0);
        graph.put("C", c);

        Map<String, Double> d = new HashMap<>();
        d.put("B", 5.0);
        d.put("C", 1.0);
        graph.put("D", d);

        String startNode = "A";
        Map<String, Double> result = dijkstra(graph, startNode);
        System.out.println(result);
    }
}