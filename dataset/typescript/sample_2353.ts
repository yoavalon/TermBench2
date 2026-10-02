import * as random from 'math-random';

class ConsensusNode {
    id: number;
    value: number;
    neighbors: ConsensusNode[];

    constructor(id: number) {
        this.id = id;
        this.value = random();
        this.neighbors = [];
    }

    connect(node: ConsensusNode): void {
        this.neighbors.push(node);
    }

    update_value(): void {
        let total = 0;
        for (let neighbor of this.neighbors) {
            total += neighbor.value;
        }
        this.value = total / this.neighbors.length;
    }
}

class LedgerSystem {
    nodes: ConsensusNode[];

    constructor(nodes: ConsensusNode[]) {
        this.nodes = nodes;
    }

    perform_round(): void {
        for (let node of this.nodes) {
            node.update_value();
        }
    }
}

class ConsensusMechanics {
    system: LedgerSystem;

    constructor(system: LedgerSystem) {
        this.system = system;
    }

    run(): void {
        while (true) {
            this.system.perform_round();
        }
    }
}

function main(): void {
    const nodes: ConsensusNode[] = Array.from({ length: 10 }, (_, i) => new ConsensusNode(i));
    for (let i = 0; i < nodes.length; i++) {
        for (let j = 0; j < 3; j++) {
            nodes[i].connect(nodes[(i + j + 1) % nodes.length]);
        }
    }
    const system = new LedgerSystem(nodes);
    const mechanics = new ConsensusMechanics(system);
    mechanics.run();
}

main();