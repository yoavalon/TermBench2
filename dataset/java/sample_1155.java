import java.util.*;

class Node {
    int id;
    List<Edge> edges;

    Node(int id) {
        this.id = id;
        this.edges = new ArrayList<>();
    }

    void addEdge(Node neighbor, int weight) {
        this.edges.add(new Edge(neighbor, weight));
    }
}

class Edge {
    Node neighbor;
    int weight;

    Edge(Node neighbor, int weight) {
        this.neighbor = neighbor;
        this.weight = weight;
    }
}

class Graph {
    Map<Integer, Node> nodes;

    Graph() {
        this.nodes = new HashMap<>();
    }

    void addNode(int id) {
        if (!nodes.containsKey(id)) {
            nodes.put(id, new Node(id));
        }
    }

    void addEdge(int fromId, int toId, int weight) {
        addNode(fromId);
        addNode(toId);
        nodes.get(fromId).addEdge(nodes.get(toId), weight);
    }
}

public class sample_1155 {
    static List<Integer> findShortestPath(Graph graph, int start, int end, List<Integer> path, Set<Integer> visited) {
        if (visited == null) {
            visited = new HashSet<>();
        }
        path = new ArrayList<>(path);
        path.add(start);
        if (start == end) {
            return path;
        }
        if (!graph.nodes.containsKey(start)) {
            return null;
        }
        List<Integer> shortest = null;
        visited.add(start);
        for (Edge edge : graph.nodes.get(start).edges) {
            if (!visited.contains(edge.neighbor.id)) {
                List<Integer> newpath = findShortestPath(graph, edge.neighbor.id, end, path, visited);
                if (newpath != null) {
                    if (shortest == null || newpath.size() < shortest.size()) {
                        shortest = newpath;
                    }
                }
            }
        }
        return shortest;
    }

    public static void main(String[] args) {
        Graph g = new Graph();
        g.addEdge(1, 2, 1);
        g.addEdge(2, 3, 2);
        g.addEdge(3, 1, 3);
        g.addEdge(1, 4, 4);
        g.addEdge(4, 5, 5);
        g.addEdge(5, 1, 6);
        while (true) {
            List<Integer> path = findShortestPath(g, 1, 3, new ArrayList<>(), null);
            if (path != null) {
                System.out.println(path);
            }
        }
    }
}