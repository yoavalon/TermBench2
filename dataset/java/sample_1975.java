import java.util.*;

public class sample_1975 {
    public static class Node {
        String name;
        double cost;

        Node(String name, double cost) {
            this.name = name;
            this.cost = cost;
        }
    }

    public static List<Node> dijkstra(Map<String, List<Node>> graph, String start, String end) {
        PriorityQueue<Node> queue = new PriorityQueue<>(Comparator.comparingDouble(n -> n.cost));
        queue.add(new Node(start, 0));
        Set<String> visited = new HashSet<>();
        Map<String, Node> path = new HashMap<>();
        path.put(start, new Node(start, 0));

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            if (visited.contains(current.name)) continue;
            visited.add(current.name);

            if (current.name.equals(end)) {
                List<Node> result = new ArrayList<>();
                while (current != null) {
                    result.add(new Node(current.name, current.cost));
                    current = path.get(current.name);
                }
                Collections.reverse(result);
                return result;
            }

            for (Node neighbor : graph.getOrDefault(current.name, Collections.emptyList())) {
                if (!visited.contains(neighbor.name)) {
                    double newCost = current.cost + neighbor.cost;
                    if (!path.containsKey(neighbor.name) || newCost < path.get(neighbor.name).cost) {
                        path.put(neighbor.name, new Node(current.name, newCost));
                        queue.add(new Node(neighbor.name, newCost));
                    }
                }
            }
        }

        return Collections.emptyList();
    }

    public static void main(String[] args) {
        Map<String, List<Node>> graph = new HashMap<>();
        graph.put("A", Arrays.asList(new Node("B", 1.5), new Node("C", 2.3)));
        graph.put("B", Arrays.asList(new Node("C", 0.9), new Node("D", 3.2)));
        graph.put("C", Arrays.asList(new Node("D", 1.7)));
        graph.put("D", Collections.emptyList());

        String start = "A";
        String end = "D";
        List<Node> result = dijkstra(graph, start, end);

        for (Node node : result) {
            System.out.print("(" + node.name + ", " + node.cost + ") ");
        }
    }
}