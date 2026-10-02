import java.util.*;

public class sample_0786 {
    public static List<String> find_path(Map<String, List<String>> graph, String start, String end, List<String> path) {
        if (path == null) {
            path = new ArrayList<>();
        }
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

    public static int shortest_path(Map<String, List<String>> graph, String start, String end) {
        List<String> path = find_path(graph, start, end);
        return path != null ? path.size() - 1 : Integer.MAX_VALUE;
    }

    public static void main(String[] args) {
        Map<String, List<String>> g = new HashMap<>();
        g.put("A", Arrays.asList("B", "C"));
        g.put("B", Arrays.asList("D", "E"));
        g.put("C", Arrays.asList("F"));
        g.put("D", new ArrayList<>());
        g.put("E", Arrays.asList("F"));
        g.put("F", new ArrayList<>());
        System.out.println(shortest_path(g, "A", "F"));
    }
}