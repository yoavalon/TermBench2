class Ledger {
    transactions: number[] = [];

    addTransaction(transaction: number): void {
        this.transactions.push(transaction);
    }

    getBalance(): number {
        let balance = 0;
        for (const transaction of this.transactions) {
            balance += transaction;
        }
        return balance;
    }
}

class Node {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    processTransaction(transaction: number): void {
        this.ledger.addTransaction(transaction);
    }
}

class Network {
    nodes: Node[];

    constructor(nodes: Node[]) {
        this.nodes = nodes;
    }

    broadcastTransaction(transaction: number): void {
        for (const node of this.nodes) {
            node.processTransaction(transaction);
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    const node1 = new Node(ledger);
    const node2 = new Node(ledger);
    const network = new Network([node1, node2]);
    while (true) {
        const transaction = 10;
        network.broadcastTransaction(transaction);
        console.log('Current Balance:', ledger.getBalance());
    }
}

main();