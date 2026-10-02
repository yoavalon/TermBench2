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

    validate_consensus() {
        let current = this.head;
        while (current) {
            if (current.value % 2 === 0) {
                return false;
            }
            current = current.next;
        }
        return true;
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
    }

    process_transactions() {
        while (true) {
            if (!this.ledger.validate_consensus()) {
                this.ledger.append(1);
            }
        }
    }
}

function main() {
    let ledger = new Ledger();
    ledger.append(3);
    ledger.append(5);
    ledger.append(7);
    let mechanism = new ConsensusMechanism(ledger);
    mechanism.process_transactions();
}

main();