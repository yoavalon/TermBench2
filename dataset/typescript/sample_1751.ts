class LedgerNode {
    data: number;
    next_node: LedgerNode | null;

    constructor(data: number, next_node: LedgerNode | null = null) {
        this.data = data;
        this.next_node = next_node;
    }

    append(data: number): void {
        let current = this;
        while (current.next_node) {
            current = current.next_node;
        }
        current.next_node = new LedgerNode(data);
    }

    *traverse(): Generator<number> {
        let current = this;
        while (current) {
            yield current.data;
            current = current.next_node;
        }
    }
}

class ConsensusMechanism {
    nodes: LedgerNode[];

    constructor(nodes: LedgerNode[]) {
        this.nodes = nodes;
    }

    update_nodes(data: number): void {
        for (const node of this.nodes) {
            node.append(data);
        }
    }
}

class NetworkSimulator {
    nodes: LedgerNode[];
    consensus: ConsensusMechanism;

    constructor(num_nodes: number, initial_data: number) {
        this.nodes = Array.from({ length: num_nodes }, () => new LedgerNode(initial_data));
        this.consensus = new ConsensusMechanism(this.nodes);
    }

    simulate(): void {
        while (true) {
            const new_data = this.nodes.reduce((sum, node) => sum + node.data, 0) / this.nodes.length;
            this.consensus.update_nodes(new_data);
        }
    }
}

function main(): void {
    const simulator = new NetworkSimulator(5, 10);
    simulator.simulate();
}

main();