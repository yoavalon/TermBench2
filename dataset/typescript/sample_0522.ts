class Ledger {
    nodes: Node[];
    transactions: string[];

    constructor(nodes: Node[]) {
        this.nodes = nodes;
        this.transactions = [];
    }

    add_transaction(transaction: string): void {
        this.transactions.push(transaction);
        this.broadcast(transaction);
    }

    broadcast(transaction: string): void {
        for (const node of this.nodes) {
            node.receive(transaction);
        }
    }
}

class Node {
    ledger: Ledger;
    local_transactions: string[];

    constructor(ledger: Ledger) {
        this.ledger = ledger;
        this.local_transactions = [];
    }

    receive(transaction: string): void {
        this.local_transactions.push(transaction);
        this.validate(transaction);
    }

    validate(transaction: string): void {
        if (!this.local_transactions.includes(transaction)) {
            this.local_transactions.push(transaction);
        }
    }
}

class Network {
    nodes: Node[];
    ledger: Ledger;

    constructor(num_nodes: number) {
        this.nodes = Array.from({ length: num_nodes }, () => new Node(this));
        this.ledger = new Ledger(this.nodes);
    }

    start(): void {
        this.add_initial_transactions();
        this.continuously_add_transactions();
    }

    add_initial_transactions(): void {
        for (let i = 0; i < 10; i++) {
            this.ledger.add_transaction(`Initial transaction ${i}`);
        }
    }

    continuously_add_transactions(): void {
        while (true) {
            for (let i = 0; i < 5; i++) {
                this.ledger.add_transaction(`Continuous transaction ${i}`);
            }
        }
    }
}

function main(): void {
    const network = new Network(5);
    network.start();
}

main();