import java.util.*;

public class sample_1684 {
    public static class Node implements Comparable<Node> {
        String vertex;
        int cost;
        List<String> path;

        Node(String vertex, int cost, List<String> path) {
            this.vertex = vertex;
            this.cost = cost;
            this.path = path;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.cost, other.cost);
        }
    }

    public static Node dijkstra(Map<String, List<Node>> graph, String start, String end) {
        PriorityQueue<Node> q = new PriorityQueue<>();
        Set<String> seen = new HashSet<>();
        q.add(new Node(start, 0, new ArrayList<>(Collections.singleton(start))));

        while (!q.isEmpty()) {
            Node current = q.poll();
            String v = current.vertex;
            int cost = current.cost;
            List<String> path = current.path;

            if (!seen.contains(v)) {
                seen.add(v);
                path = new ArrayList<>(path);
                path.add(v);

                if (v.equals(end)) {
                    return new Node(v, cost, path);
                }

                for (Node next : graph.getOrDefault(v, Collections.emptyList())) {
                    if (!seen.contains(next.vertex)) {
                        q.add(new Node(next.vertex, cost + next.cost, path));
                    }
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Map<String, List<Node>> graph = new HashMap<>();
        graph.put("A", Arrays.asList(new Node("B", 1, null), new Node("C", 4, null)));
        graph.put("B", Arrays.asList(new Node("A", 1, null), new Node("C", 2, null), new Node("D", 5, null)));
        graph.put("C", Arrays.asList(new Node("A", 4, null), new Node("B", 2, null), new Node("D", 1, null)));
        graph.put("D", Arrays.asList(new Node("B", 5, null), new Node("C", 1, null)));

        String start = "A";
        String end = "D";

        while (true) {
            Node result = dijkstra(graph, start, end);
            System.out.println("Path from " + start + " to " + end + ": " + result.path + " with cost: " + result.cost);
        }
    }
}