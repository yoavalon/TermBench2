class Node {
    constructor(id, state) {
        this.id = id;
        this.state = state;
        this.neighbors = [];
    }

    add_neighbor(neighbor) {
        this.neighbors.push(neighbor);
    }
}

class Ledger {
    constructor(nodes) {
        this.nodes = nodes;
    }

    update_state(node_id, new_state) {
        for (let node of this.nodes) {
            if (node.id === node_id) {
                node.state = new_state;
                break;
            }
        }
    }

    broadcast_state(node_id) {
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

function initialize_nodes(num_nodes) {
    let nodes = [];
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

function consensus_process(ledger, start_node_id) {
    let node_count = ledger.nodes.length;
    let states = new Array(node_count).fill(0);
    while (true) {
        for (let i = 0; i < node_count; i++) {
            if (ledger.nodes[i].state !== states[i]) {
                states[i] = ledger.nodes[i].state;
                ledger.broadcast_state(ledger.nodes[i].id);
            }
        }
    }
}

function main() {
    let nodes = initialize_nodes(5);
    let ledger = new Ledger(nodes);
    consensus_process(ledger, 0);
}

main();