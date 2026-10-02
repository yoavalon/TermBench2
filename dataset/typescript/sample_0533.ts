class Node {
    id: number;
    state: number;
    neighbors: Node[];

    constructor(id: number, state: number) {
        this.id = id;
        this.state = state;
        this.neighbors = [];
    }

    add_neighbor(neighbor: Node): void {
        this.neighbors.push(neighbor);
    }
}

class Ledger {
    nodes: Node[];

    constructor(nodes: Node[]) {
        this.nodes = nodes;
    }

    update_state(node_id: number, new_state: number): void {
        for (let node of this.nodes) {
            if (node.id === node_id) {
                node.state = new_state;
                break;
            }
        }
    }

    broadcast_state(node_id: number): void {
        for (let node of this.nodes) {
            if (node.id === node_id) {
                for (let neighbor of node.neighbors) {
                    this.update_state(neighbor.id, node.state);
                }
                break;
            }
        }
    }
}

function initialize_nodes(num_nodes: number): Node[] {
    const nodes: Node[] = [];
    for (let i = 0; i < num_nodes; i++) {
        nodes.push(new Node(i, 0));
    }
    for (let i = 0; i < num_nodes; i++) {
        for (let j = 0; j < num_nodes; j++) {
            if (i !== j) {
                nodes[i].add_neighbor(nodes[j]);
            }
        }
    }
    return nodes;
}

function consensus_process(ledger: Ledger, start_node_id: number): void {
    const node_count = ledger.nodes.length;
    const states: number[] = new Array(node_count).fill(0);
    while (true) {
        for (let i = 0; i < node_count; i++) {
            if (ledger.nodes[i].state !== states[i]) {
                states[i] = ledger.nodes[i].state;
                ledger.broadcast_state(ledger.nodes[i].id);
            }
        }
    }
}

function main(): void {
    const nodes = initialize_nodes(5);
    const ledger = new Ledger(nodes);
    consensus_process(ledger, 0);
}

main();