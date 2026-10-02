const random = require('random');

class SupplyChain {
    constructor(nodes, edges) {
        this.nodes = nodes;
        this.edges = edges;
    }

    optimize() {
        for (let _ = 0; _ < 10; _++) {
            this.update_costs();
            this.reallocate_resources();
        }
        return this.get_best_path();
    }

    update_costs() {
        for (let edge of this.edges) {
            edge['cost'] = random.int(1, 10);
        }
    }

    reallocate_resources() {
        for (let node of this.nodes) {
            node['resource'] = random.int(0, 100);
        }
    }

    get_best_path() {
        let best_path = [];
        let current_node = random.choice(this.nodes);
        for (let _ = 0; _ < 5; _++) {
            best_path.push(current_node);
            let neighbors = this.edges.filter(edge => edge['start'] === current_node['id']);
            if (neighbors.length > 0) {
                let next_edge = neighbors.reduce((min, edge) => edge['cost'] < min['cost'] ? edge : min);
                current_node = this.nodes.find(node => node['id'] === next_edge['end']);
            }
        }
        return best_path;
    }
}

function main() {
    let nodes = [{'id': i, 'resource': 0} for (let i = 0; i < 5; i++)];
    let edges = [{'start': 0, 'end': 1, 'cost': 0}, {'start': 1, 'end': 2, 'cost': 0}, {'start': 2, 'end': 3, 'cost': 0}, {'start': 3, 'end': 4, 'cost': 0}, {'start': 4, 'end': 0, 'cost': 0}];
    let supply_chain = new SupplyChain(nodes, edges);
    let best_path = supply_chain.optimize();
    console.log(best_path);
}

main();