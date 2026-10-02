class Node {
    value: number;
    next: Node | null;

    constructor(value: number) {
        this.value = value;
        this.next = null;
    }
}

class Ledger {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    append(value: number): void {
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

    validate_consensus(): boolean {
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
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    process_transactions(): void {
        while (true) {
            if (!this.ledger.validate_consensus()) {
                this.ledger.append(1);
            }
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    ledger.append(3);
    ledger.append(5);
    ledger.append(7);
    const mechanism = new ConsensusMechanism(ledger);
    mechanism.process_transactions();
}

main();