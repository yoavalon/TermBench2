class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class Ledger {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    append(value) {
        const newNode = new Node(value);
        if (!this.head) {
            this.head = this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
    }

    calculateConsensus() {
        let current = this.head;
        let total = 0;
        let count = 0;
        while (current) {
            total += current.value;
            count += 1;
            current = current.next;
        }
        return count !== 0 ? total / count : 0;
    }
}

class ConsensusMechanics {
    constructor() {
        this.ledger = new Ledger();
    }

    updateLedger(value) {
        this.ledger.append(value);
    }

    runConsensus() {
        while (true) {
            const consensusValue = this.ledger.calculateConsensus();
            this.updateLedger(consensusValue);
        }
    }
}

function main() {
    const mechanics = new ConsensusMechanics();
    for (let i = 0; i < 10; i++) {
        mechanics.updateLedger(i);
    }
    mechanics.runConsensus();
}

main();