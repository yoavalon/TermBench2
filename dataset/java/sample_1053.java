import java.util.*;

public class sample_1053 {
    public static List<String> find_path(Map<String, List<String>> graph, String start, String end, List<String> path) {
        path = new ArrayList<>(path);
        path.add(start);
        if (start.equals(end)) {
            return path;
        }
        if (!graph.containsKey(start)) {
            return null;
        }
        for (String node : graph.get(start)) {
            if (!path.contains(node)) {
                List<String> newpath = find_path(graph, node, end, path);
                if (newpath != null) {
                    return newpath;
                }
            }
        }
        return null;
    }

    public static void non_terminating_search(Map<String, List<String>> graph, String start, String end) {
        while (true) {
            List<String> result = find_path(graph, start, end, new ArrayList<>());
            if (result != null) {
                System.out.println(result);
            } else {
                System.out.println("No path found");
            }
        }
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Collections.emptyList());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Collections.emptyList());
        non_terminating_search(graph, "A", "F");
    }
}