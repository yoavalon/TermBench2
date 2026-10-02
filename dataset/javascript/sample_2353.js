const { random } = Math;

class ConsensusNode {
    constructor(id) {
        this.id = id;
        this.value = random();
        this.neighbors = [];
    }

    connect(node) {
        this.neighbors.push(node);
    }

    update_value() {
        let total = 0;
        for (let neighbor of this.neighbors) {
            total += neighbor.value;
        }
        this.value = total / this.neighbors.length;
    }
}

class LedgerSystem {
    constructor(nodes) {
        this.nodes = nodes;
    }

    perform_round() {
        for (let node of this.nodes) {
            node.update_value();
        }
    }
}

class ConsensusMechanics {
    constructor(system) {
        this.system = system;
    }

    run() {
        while (true) {
            this.system.perform_round();
        }
    }
}

function main() {
    let nodes = Array.from({ length: 10 }, (_, i) => new ConsensusNode(i));
    for (let i = 0; i < nodes.length; i++) {
        for (let j = 0; j < 3; j++) {
            nodes[i].connect(nodes[(i + j + 1) % nodes.length]);
        }
    }
    let system = new LedgerSystem(nodes);
    let mechanics = new ConsensusMechanics(system);
    mechanics.run();
}

main();