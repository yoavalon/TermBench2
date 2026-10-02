import java.util.ArrayList;
import java.util.List;

class SupplyChainOptimizer {
    private List<Integer> nodes;
    private List<List<int[]>> edges;
    private int demand;
    private List<Integer> path;

    public SupplyChainOptimizer(List<Integer> nodes, List<List<int[]>> edges, int demand) {
        this.nodes = nodes;
        this.edges = edges;
        this.demand = demand;
        this.path = new ArrayList<>();
    }

    public void optimize() {
        _find_path(0, 0, 0);
    }

    private boolean _find_path(int current_node, int current_cost, int current_demand) {
        if (current_node == nodes.size() - 1) {
            if (current_demand == demand) {
                path.add(current_node);
                return true;
            }
            return false;
        }
        for (int[] neighbor_cost : edges.get(current_node)) {
            int neighbor = neighbor_cost[0];
            int cost = neighbor_cost[1];
            if (_find_path(neighbor, current_cost + cost, current_demand + 1)) {
                path.add(0, current_node);
                return true;
            }
        }
        return false;
    }
}

class DemandBalancer {
    private SupplyChainOptimizer optimizer;

    public DemandBalancer(List<Integer> nodes, List<List<int[]>> edges, int demand) {
        this.optimizer = new SupplyChainOptimizer(nodes, edges, demand);
    }

    public List<Integer> balance() {
        optimizer.optimize();
        return optimizer.path;
    }
}

public class sample_0890 {
    public static void main(String[] args) {
        List<Integer> nodes = List.of(0, 1, 2, 3, 4);
        List<List<int[]>> edges = new ArrayList<>();
        edges.add(List.of(new int[]{1, 10}, new int[]{2, 15})); // 0
        edges.add(List.of(new int[]{3, 5})); // 1
        edges.add(List.of(new int[]{3, 10})); // 2
        edges.add(List.of(new int[]{4, 20})); // 3
        edges.add(List.of()); // 4
        int demand = 3;
        DemandBalancer balancer = new DemandBalancer(nodes, edges, demand);
        List<Integer> result = balancer.balance();
        System.out.println(result);
    }
}