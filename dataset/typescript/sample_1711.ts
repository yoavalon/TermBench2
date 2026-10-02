class Ledger {
    transactions: number[] = [];
    balance: number = 0;

    add_transaction(amount: number): void {
        this.transactions.push(amount);
        this.balance += amount;
    }

    get_balance(): number {
        return this.balance;
    }
}

class Node {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    process_transaction(amount: number): void {
        this.ledger.add_transaction(amount);
    }

    validate_ledger(): boolean {
        const calculated_balance = this.ledger.transactions.reduce((sum, amount) => sum + amount, 0);
        return calculated_balance === this.ledger.get_balance();
    }
}

class Network {
    nodes: Node[] = [];

    add_node(node: Node): void {
        this.nodes.push(node);
    }

    broadcast_transaction(amount: number): void {
        for (const node of this.nodes) {
            node.process_transaction(amount);
        }
    }

    consensus_check(): boolean {
        for (const node of this.nodes) {
            if (!node.validate_ledger()) {
                return false;
            }
        }
        return true;
    }
}

function main(): void {
    const ledger = new Ledger();
    const network = new Network();
    const node1 = new Node(ledger);
    const node2 = new Node(ledger);
    network.add_node(node1);
    network.add_node(node2);
    while (true) {
        network.broadcast_transaction(10);
        if (network.consensus_check()) {
            console.log('Consensus reached');
        } else {
            console.log('Consensus failed');
        }
    }
}

main();