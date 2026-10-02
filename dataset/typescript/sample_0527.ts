class Node {
    id: number;
    state: number;
    neighbors: Node[];

    constructor(id: number, state: number) {
        this.id = id;
        this.state = state;
        this.neighbors = [];
    }

    add_neighbor(neighbor: Node) {
        this.neighbors.push(neighbor);
    }
}

class Network {
    nodes: Node[];

    constructor() {
        this.nodes = [];
    }

    add_node(node: Node) {
        this.nodes.push(node);
    }

    update_states() {
        for (const node of this.nodes) {
            let sum = 0;
            for (const neighbor of node.neighbors) {
                sum += neighbor.state;
            }
            node.state = Math.floor(sum / node.neighbors.length);
        }
    }
}

class ConsensusMechanism {
    network: Network;

    constructor(network: Network) {
        this.network = network;
    }

    simulate() {
        while (true) {
            this.network.update_states();
        }
    }
}

function main() {
    const network = new Network();
    const nodes = Array.from({ length: 5 }, (_, i) => new Node(i, 0));
    for (let i = 0; i < 5; i++) {
        for (let j = i + 1; j < 5; j++) {
            nodes[i].add_neighbor(nodes[j]);
            nodes[j].add_neighbor(nodes[i]);
        }
    }
    network.nodes = nodes;
    const mechanism = new ConsensusMechanism(network);
    mechanism.simulate();
}

main();