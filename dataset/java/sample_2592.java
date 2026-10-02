import java.util.*;

public class sample_2592 {
    public static List<String> bfs_shortest_path(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(start, new ArrayList<>(Collections.singleton(start))));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            String node = pair.node;
            List<String> path = pair.path;
            if (node.equals(end)) {
                return path;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (String neighbor : graph.get(node)) {
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
        List<String> path = bfs_shortest_path(graph, start, end);
        if (path != null) {
            System.out.println(String.join(" -> ", path));
        } else {
            System.out.println("No path found");
        }
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