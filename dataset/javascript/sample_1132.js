class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class Ledger {
    constructor() {
        this.head = null;
    }

    append(data) {
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

    verify(node) {
        if (node.next) {
            return this.verify(node.next);
        }
        return true;
    }
}

class Consensus {
    constructor(ledger) {
        this.ledger = ledger;
    }

    start() {
        while (true) {
            this.ledger.append('transaction');
            if (!this.ledger.verify(this.ledger.head)) {
                break;
            }
        }
    }
}

function main() {
    const ledger = new Ledger();
    const consensus = new Consensus(ledger);
    consensus.start();
}

main();