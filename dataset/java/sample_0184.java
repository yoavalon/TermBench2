import java.util.*;

public class sample_0184 {
    static int bfs(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(start, 0));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            String node = current.node;
            int dist = current.dist;
            if (node.equals(end)) {
                return dist;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (String neighbor : graph.getOrDefault(node, Collections.emptyList())) {
                    queue.add(new Pair(neighbor, dist + 1));
                }
            }
        }
        return -1;
    }

    static class Pair {
        String node;
        int dist;

        Pair(String node, int dist) {
            this.node = node;
            this.dist = dist;
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
        String start = "A";
        String end = "F";
        System.out.println(bfs(graph, start, end));
    }
}