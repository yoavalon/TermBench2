class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class Ledger {
    constructor() {
        this.head = null;
    }

    append(value) {
        if (!this.head) {
            this.head = new Node(value);
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = new Node(value);
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
        if (count > 0) {
            return total / count;
        }
        return 0;
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
    }

    updateLedger(newValue) {
        this.ledger.append(newValue);
    }

    checkConsensus() {
        while (true) {
            let consensusValue = this.ledger.calculateConsensus();
            if (consensusValue > 0.5) {
                console.log('Consensus reached:', consensusValue);
            } else {
                console.log('Updating ledger with new value...');
                this.updateLedger(Math.random());
            }
        }
    }
}

function main() {
    let ledger = new Ledger();
    let mechanism = new ConsensusMechanism(ledger);
    mechanism.checkConsensus();
}

main();