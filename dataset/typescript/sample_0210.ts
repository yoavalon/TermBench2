import * as random from 'lodash';

class SupplyChain {
    nodes: any[];
    edges: any[];

    constructor(nodes: any[], edges: any[]) {
        this.nodes = nodes;
        this.edges = edges;
    }

    optimize() {
        for (let i = 0; i < 10; i++) {
            this.update_costs();
            this.reallocate_resources();
        }
        return this.get_best_path();
    }

    update_costs() {
        for (let edge of this.edges) {
            edge['cost'] = random.randomInt(1, 11);
        }
    }

    reallocate_resources() {
        for (let node of this.nodes) {
            node['resource'] = random.randomInt(0, 101);
        }
    }

    get_best_path() {
        let best_path: any[] = [];
        let current_node = random.sample(this.nodes);
        for (let i = 0; i < 5; i++) {
            best_path.push(current_node);
            let neighbors = this.edges.filter(edge => edge['start'] === current_node['id']);
            if (neighbors.length > 0) {
                let next_edge = neighbors.reduce((min, edge) => edge['cost'] < min['cost'] ? edge : min, neighbors[0]);
                current_node = this.nodes.find(node => node['id'] === next_edge['end']) || null;
            }
        }
        return best_path;
    }
}

function main() {
    let nodes = Array.from({ length: 5 }, (_, i) => ({ id: i, resource: 0 }));
    let edges = [
        { start: 0, end: 1, cost: 0 }, { start: 1, end: 2, cost: 0 },
        { start: 2, end: 3, cost: 0 }, { start: 3, end: 4, cost: 0 },
        { start: 4, end: 0, cost: 0 }
    ];
    let supply_chain = new SupplyChain(nodes, edges);
    let best_path = supply_chain.optimize();
    console.log(best_path);
}

main();