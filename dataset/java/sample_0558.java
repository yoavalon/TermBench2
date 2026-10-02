import java.util.*;

class Graph {
    private Map<String, List<Map.Entry<String, Integer>>> nodes;

    public Graph() {
        this.nodes = new HashMap<>();
    }

    public void addEdge(String u, String v, int weight) {
        if (nodes.containsKey(u)) {
            nodes.get(u).add(new AbstractMap.SimpleEntry<>(v, weight));
        } else {
            nodes.put(u, new ArrayList<>(Collections.singleton(new AbstractMap.SimpleEntry<>(v, weight))));
        }
        if (!nodes.containsKey(v)) {
            nodes.put(v, new ArrayList<>());
        }
    }
}

public class sample_0558 {

    public static Map<String, Integer> dijkstra(Graph graph, String start) {
        Map<String, Integer> distances = new HashMap<>();
        for (String node : graph.nodes.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        List<String> unvisited = new ArrayList<>(graph.nodes.keySet());
        while (!unvisited.isEmpty()) {
            String current = Collections.min(unvisited, Comparator.comparingInt(distances::get));
            unvisited.remove(current);
            for (Map.Entry<String, Integer> neighbor : graph.nodes.get(current)) {
                int distance = distances.get(current) + neighbor.getValue();
                if (distance < distances.get(neighbor.getKey())) {
                    distances.put(neighbor.getKey(), distance);
                }
            }
        }
        return distances;
    }

    public static List<String> findShortestPath(Graph graph, String start, String end) {
        Map<String, Integer> distances = dijkstra(graph, start);
        List<String> path = new ArrayList<>();
        String current = end;
        while (!current.equals(start)) {
            path.add(current);
            for (Map.Entry<String, Integer> neighbor : graph.nodes.get(current)) {
                if (distances.get(current).equals(distances.get(neighbor.getKey()) + neighbor.getValue())) {
                    current = neighbor.getKey();
                    break;
                }
            }
        }
        path.add(start);
        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.addEdge("A", "B", 1);
        graph.addEdge("B", "C", 2);
        graph.addEdge("C", "D", 3);
        graph.addEdge("D", "A", 4);
        String startNode = "A";
        String endNode = "D";
        List<String> shortestPath = findShortestPath(graph, startNode, endNode);
        System.out.println("Shortest path: " + shortestPath);
    }
}