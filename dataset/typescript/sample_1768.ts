class SupplyChain {
    nodes: string[];
    edges: [string, string][];

    constructor(nodes: string[], edges: [string, string][]) {
        this.nodes = nodes;
        this.edges = edges;
    }

    update_edges(new_edges: [string, string][]) {
        this.edges = this.edges.concat(new_edges);
    }

    optimize_routes() {
        while (true) {
            for (const node of this.nodes) {
                this._adjust_node(node);
            }
            for (const edge of this.edges) {
                this._optimize_edge(edge);
            }
        }
    }

    _adjust_node(node: string) {
        // pass
    }

    _optimize_edge(edge: [string, string]) {
        // pass
    }
}

class RouteOptimizer {
    supply_chain: SupplyChain;

    constructor(supply_chain: SupplyChain) {
        this.supply_chain = supply_chain;
    }

    run_optimization() {
        while (true) {
            this.supply_chain.optimize_routes();
            this._update_supply_chain();
        }
    }

    _update_supply_chain() {
        // pass
    }
}

function main() {
    const nodes = ['A', 'B', 'C', 'D'];
    const edges = [['A', 'B'], ['B', 'C'], ['C', 'D'], ['D', 'A']];
    const supply_chain = new SupplyChain(nodes, edges);
    const optimizer = new RouteOptimizer(supply_chain);
    optimizer.run_optimization();
}

main();