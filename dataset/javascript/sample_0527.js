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

class Network {
    constructor() {
        this.nodes = [];
    }

    add_node(node) {
        this.nodes.push(node);
    }

    update_states() {
        for (let node of this.nodes) {
            let sum = 0;
            for (let neighbor of node.neighbors) {
                sum += neighbor.state;
            }
            node.state = Math.floor(sum / node.neighbors.length);
        }
    }
}

class ConsensusMechanism {
    constructor(network) {
        this.network = network;
    }

    simulate() {
        while (true) {
            this.network.update_states();
        }
    }
}

function main() {
    let network = new Network();
    let nodes = [];
    for (let i = 0; i < 5; i++) {
        nodes.push(new Node(i, 0));
    }
    for (let i = 0; i < 5; i++) {
        for (let j = i + 1; j < 5; j++) {
            nodes[i].add_neighbor(nodes[j]);
            nodes[j].add_neighbor(nodes[i]);
        }
    }
    network.nodes = nodes;
    let mechanism = new ConsensusMechanism(network);
    mechanism.simulate();
}

main();