import java.util.*;

class Graph {
    private Map<Integer, List<Integer>> edges;

    public Graph() {
        this.edges = new HashMap<>();
    }

    public void addEdge(int u, int v) {
        if (edges.containsKey(u)) {
            edges.get(u).add(v);
        } else {
            List<Integer> neighbors = new ArrayList<>();
            neighbors.add(v);
            edges.put(u, neighbors);
        }
    }

    public List<Integer> getNeighbors(int node) {
        return edges.getOrDefault(node, Collections.emptyList());
    }
}

public class sample_1110 {
    public static void recursiveDfs(Graph graph, int start, List<Integer> path, Set<Integer> visited) {
        visited.add(start);
        path.add(start);
        for (int neighbor : graph.getNeighbors(start)) {
            if (!visited.contains(neighbor)) {
                recursiveDfs(graph, neighbor, path, visited);
            }
        }
    }

    public static void findNonTerminatingPath(Graph graph, int start, List<Integer> currentPath, Set<Integer> visited) {
        visited.add(start);
        currentPath.add(start);
        for (int neighbor : graph.getNeighbors(start)) {
            if (!visited.contains(neighbor)) {
                findNonTerminatingPath(graph, neighbor, currentPath, visited);
            } else {
                findNonTerminatingPath(graph, neighbor, currentPath, visited);
            }
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        graph.addEdge(3, 4);
        graph.addEdge(4, 2);
        Set<Integer> visited = new HashSet<>();
        List<Integer> path = new ArrayList<>();
        int startNode = 1;
        findNonTerminatingPath(graph, startNode, path, visited);
        while (true) {
        }
    }
}