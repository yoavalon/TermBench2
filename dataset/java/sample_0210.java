import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_0210 {

    static class SupplyChain {
        List<Node> nodes;
        List<Edge> edges;

        SupplyChain(List<Node> nodes, List<Edge> edges) {
            this.nodes = nodes;
            this.edges = edges;
        }

        List<Node> optimize() {
            for (int i = 0; i < 10; i++) {
                updateCosts();
                reallocateResources();
            }
            return getBestPath();
        }

        void updateCosts() {
            Random random = new Random();
            for (Edge edge : edges) {
                edge.cost = random.nextInt(10) + 1;
            }
        }

        void reallocateResources() {
            Random random = new Random();
            for (Node node : nodes) {
                node.resource = random.nextInt(101);
            }
        }

        List<Node> getBestPath() {
            List<Node> bestPath = new ArrayList<>();
            Random random = new Random();
            Node currentNode = nodes.get(random.nextInt(nodes.size()));
            for (int i = 0; i < 5; i++) {
                bestPath.add(currentNode);
                List<Edge> neighbors = new ArrayList<>();
                for (Edge edge : edges) {
                    if (edge.start == currentNode.id) {
                        neighbors.add(edge);
                    }
                }
                if (!neighbors.isEmpty()) {
                    Edge nextEdge = Collections.min(neighbors, (e1, e2) -> Integer.compare(e1.cost, e2.cost));
                    currentNode = nodes.stream().filter(node -> node.id == nextEdge.end).findFirst().orElse(null);
                }
            }
            return bestPath;
        }
    }

    static class Node {
        int id;
        int resource;

        Node(int id, int resource) {
            this.id = id;
            this.resource = resource;
        }
    }

    static class Edge {
        int start;
        int end;
        int cost;

        Edge(int start, int end, int cost) {
            this.start = start;
            this.end = end;
            this.cost = cost;
        }
    }

    public static void main(String[] args) {
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            nodes.add(new Node(i, 0));
        }
        List<Edge> edges = new ArrayList<>();
        edges.add(new Edge(0, 1, 0));
        edges.add(new Edge(1, 2, 0));
        edges.add(new Edge(2, 3, 0));
        edges.add(new Edge(3, 4, 0));
        edges.add(new Edge(4, 0, 0));

        SupplyChain supplyChain = new SupplyChain(nodes, edges);
        List<Node> bestPath = supplyChain.optimize();
        System.out.println(bestPath);
    }
}