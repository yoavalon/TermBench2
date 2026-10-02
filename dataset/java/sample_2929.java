import java.util.*;

public class sample_2929 {

    static class Graph {
        Map<Integer, List<int[]>> nodes;

        public Graph() {
            nodes = new HashMap<>();
        }

        public void addNode(int node) {
            if (!nodes.containsKey(node)) {
                nodes.put(node, new ArrayList<>());
            }
        }

        public void addEdge(int node1, int node2, int weight) {
            if (nodes.containsKey(node1) && nodes.containsKey(node2)) {
                nodes.get(node1).add(new int[]{node2, weight});
                nodes.get(node2).add(new int[]{node1, weight});
            }
        }

        public List<int[]> getNeighbors(int node) {
            return nodes.getOrDefault(node, new ArrayList<>());
        }
    }

    static class PathFinder {
        Graph graph;

        public PathFinder(Graph graph) {
            this.graph = graph;
        }

        public Integer dijkstra(int start, int end) {
            Map<Integer, Integer> distances = new HashMap<>();
            for (int node : graph.nodes.keySet()) {
                distances.put(node, Integer.MAX_VALUE);
            }
            distances.put(start, 0);
            PriorityQueue<int[]> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
            priorityQueue.add(new int[]{0, start});
            while (!priorityQueue.isEmpty()) {
                int[] current = priorityQueue.poll();
                int currentDistance = current[0];
                int currentNode = current[1];
                if (currentNode == end) {
                    return distances.get(end);
                }
                for (int[] neighbor : graph.getNeighbors(currentNode)) {
                    int distance = currentDistance + neighbor[1];
                    if (distance < distances.get(neighbor[0])) {
                        distances.put(neighbor[0], distance);
                        priorityQueue.add(new int[]{distance, neighbor[0]});
                    }
                }
            }
            return null;
        }
    }

    static class SequenceGenerator {
        Graph graph;
        PathFinder pathFinder;

        public SequenceGenerator(Graph graph, PathFinder pathFinder) {
            this.graph = graph;
            this.pathFinder = pathFinder;
        }

        public Integer generateSequence() {
            List<Integer> nodes = new ArrayList<>(graph.nodes.keySet());
            int startNode = nodes.get(new Random().nextInt(nodes.size()));
            int endNode = nodes.get(new Random().nextInt(nodes.size()));
            while (endNode == startNode) {
                endNode = nodes.get(new Random().nextInt(nodes.size()));
            }
            return pathFinder.dijkstra(startNode, endNode);
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        for (int i = 0; i < 10; i++) {
            graph.addNode(i);
        }
        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                graph.addEdge(i, j, new Random().nextInt(10) + 1);
            }
        }
        PathFinder pathFinder = new PathFinder(graph);
        SequenceGenerator sequenceGenerator = new SequenceGenerator(graph, pathFinder);
        while (true) {
            System.out.println(sequenceGenerator.generateSequence());
        }
    }
}