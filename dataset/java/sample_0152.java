import java.util.*;

public class sample_0152 {
    static List<String> bfs(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(start, new ArrayList<>(Collections.singletonList(start))));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            String node = current.node;
            List<String> path = current.path;
            if (node.equals(end)) {
                return path;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (String neighbor : graph.getOrDefault(node, Collections.emptyList())) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(neighbor);
                    queue.add(new Pair(neighbor, newPath));
                }
            }
        }
        return new ArrayList<>();
    }

    static List<String> find_shortest_path(Map<String, List<String>> graph, String start, String end) {
        return bfs(graph, start, end);
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Collections.emptyList());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Collections.emptyList());
        String start_node = "A";
        String end_node = "F";
        List<String> path = find_shortest_path(graph, start_node, end_node);
        System.out.println(path);
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