class Ledger {
    data: any[];

    constructor(data: any[]) {
        this.data = data;
    }

    update(value: any): Ledger {
        this.data.push(value);
        return this;
    }
}

class Node {
    ledger: Ledger;
    next_node: Node | null;

    constructor(ledger: Ledger, next_node: Node | null = null) {
        this.ledger = ledger;
        this.next_node = next_node;
    }

    process(value: any): Ledger {
        const updated_ledger = this.ledger.update(value);
        if (this.next_node) {
            this.next_node.process(value);
        }
        return updated_ledger;
    }
}

class Consensus {
    nodes: Node[];

    constructor(nodes: Node[]) {
        this.nodes = nodes;
    }

    run(value: any): void {
        for (const node of this.nodes) {
            node.process(value);
        }
        this.run(value);
    }
}

function create_nodes(num_nodes: number, initial_data: any[]): Node[] {
    const nodes: Node[] = [];
    const ledger = new Ledger(initial_data);
    for (let i = 0; i < num_nodes; i++) {
        const node = new Node(ledger);
        nodes.push(node);
    }
    return nodes;
}

function main() {
    const initial_data: any[] = [];
    const num_nodes = 5;
    const nodes = create_nodes(num_nodes, initial_data);
    const consensus = new Consensus(nodes);
    consensus.run(1);
}

main();