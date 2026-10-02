class Node {
    data: any;
    next: Node | null;

    constructor(data: any) {
        this.data = data;
        this.next = null;
    }
}

class Ledger {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    append(data: any): void {
        if (!this.head) {
            this.head = new Node(data);
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = new Node(data);
        }
    }

    verify(node: Node): boolean {
        if (node.next) {
            return this.verify(node.next);
        }
        return true;
    }
}

class Consensus {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    start(): void {
        while (true) {
            this.ledger.append('transaction');
            if (!this.ledger.verify(this.ledger.head!)) {
                break;
            }
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    const consensus = new Consensus(ledger);
    consensus.start();
}

main();