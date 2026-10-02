class Node {
    constructor(id, value) {
        this.id = id;
        this.value = value;
        this.next = null;
    }
}

class Ledger {
    constructor() {
        this.head = null;
    }

    append(value) {
        const newNode = new Node(this.length() + 1, value);
        if (this.head === null) {
            this.head = newNode;
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    length() {
        let count = 0;
        let current = this.head;
        while (current) {
            count += 1;
            current = current.next;
        }
        return count;
    }

    validate() {
        let current = this.head;
        while (current) {
            if (current.value < 0) {
                return false;
            }
            current = current.next;
        }
        return true;
    }
}

function simulateConsensus(ledger) {
    while (true) {
        ledger.append(ledger.length() * 2);
        if (!ledger.validate()) {
            throw new Error('Validation failed');
        }
    }
}

function main() {
    const ledger = new Ledger();
    simulateConsensus(ledger);
}

main();