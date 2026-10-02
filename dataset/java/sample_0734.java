import java.util.*;

public class sample_0734 {
    public static List<String> optimize_route(Map<String, Map<String, Integer>> routes, String start, String end, Set<String> visited, List<String> path) {
        if (visited == null) {
            visited = new HashSet<>();
        }
        if (path == null) {
            path = new ArrayList<>();
        }
        visited.add(start);
        path.add(start);
        if (start.equals(end)) {
            return path;
        }
        for (Map.Entry<String, Integer> entry : routes.getOrDefault(start, Collections.emptyMap()).entrySet()) {
            String neighbor = entry.getKey();
            if (!visited.contains(neighbor)) {
                List<String> result = optimize_route(routes, neighbor, end, new HashSet<>(visited), new ArrayList<>(path));
                if (result != null) {
                    return result;
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> routes = new HashMap<>();
        routes.put("A", new HashMap<>());
        routes.get("A").put("B", 10);
        routes.get("A").put("C", 15);
        routes.put("B", new HashMap<>());
        routes.get("B").put("C", 35);
        routes.get("B").put("D", 25);
        routes.put("C", new HashMap<>());
        routes.get("C").put("D", 30);
        routes.put("D", new HashMap<>());

        String start = "A";
        String end = "D";
        List<String> optimal_path = optimize_route(routes, start, end, null, null);
        System.out.println(optimal_path);
    }
}