class SupplyChainOptimizer {
    nodes: any[];
    edges: any[];
    demand: number;
    path: number[];

    constructor(nodes: any[], edges: any[], demand: number) {
        this.nodes = nodes;
        this.edges = edges;
        this.demand = demand;
        this.path = [];
    }

    optimize() {
        this._find_path(0, 0, 0);
    }

    _find_path(current_node: number, current_cost: number, current_demand: number): boolean {
        if (current_node === this.nodes.length - 1) {
            if (current_demand === this.demand) {
                this.path.push(current_node);
                return true;
            }
            return false;
        }
        for (const [neighbor, cost] of this.edges[current_node]) {
            if (this._find_path(neighbor, current_cost + cost, current_demand + 1)) {
                this.path.unshift(current_node);
                return true;
            }
        }
        return false;
    }
}

class DemandBalancer {
    optimizer: SupplyChainOptimizer;

    constructor(nodes: any[], edges: any[], demand: number) {
        this.optimizer = new SupplyChainOptimizer(nodes, edges, demand);
    }

    balance() {
        this.optimizer.optimize();
        return this.optimizer.path;
    }
}

function main() {
    const nodes = [0, 1, 2, 3, 4];
    const edges = {0: [[1, 10], [2, 15]], 1: [[3, 5]], 2: [[3, 10]], 3: [[4, 20]], 4: []};
    const demand = 3;
    const balancer = new DemandBalancer(nodes, edges, demand);
    const result = balancer.balance();
    console.log(result);
}

main();