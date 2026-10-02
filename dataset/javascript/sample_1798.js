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

    verify_consensus() {
        let current = this.head;
        while (current) {
            if (!this.is_valid(current.value)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    is_valid(value) {
        return value % 2 === 0;
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
    }

    run() {
        while (true) {
            if (!this.ledger.verify_consensus()) {
                this.correct_mutation();
            }
            this.ledger.append(this.generate_new_value());
        }
    }

    correct_mutation() {
        let current = this.ledger.head;
        while (current) {
            if (!this.ledger.is_valid(current.value)) {
                current.value = this.correct_value(current.value);
            }
            current = current.next;
        }
    }

    generate_new_value() {
        return Math.floor(Math.random() * 101);
    }

    correct_value(value) {
        return value % 2 !== 0 ? value + 1 : value;
    }
}

function main() {
    const ledger = new Ledger();
    const mechanism = new ConsensusMechanism(ledger);
    mechanism.run();
}

main();