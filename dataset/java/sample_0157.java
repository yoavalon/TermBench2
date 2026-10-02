import java.util.*;

public class sample_0157 {
    public static List<String> bfs(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(start, new ArrayList<>(Arrays.asList(start))));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            String node = pair.node;
            List<String> path = pair.path;
            if (!visited.contains(node)) {
                visited.add(node);
                if (node.equals(end)) {
                    return path;
                }
                for (String neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                    if (!visited.contains(neighbor)) {
                        List<String> newPath = new ArrayList<>(path);
                        newPath.add(neighbor);
                        queue.add(new Pair(neighbor, newPath));
                    }
                }
            }
        }
        return null;
    }

    public static int find_shortest_path(Map<String, List<String>> graph, String start, String end) {
        List<String> path = bfs(graph, start, end);
        if (path != null) {
            return path.size() - 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", new ArrayList<>());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", new ArrayList<>());
        String start = "A";
        String end = "F";
        int result = find_shortest_path(graph, start, end);
        System.out.println(result);
    }

    static class Pair {
        String node;
        List<String> path;

        Pair(String node, List<String> path) {
            this.node = node;
            this.path = path;
        }
    }
}