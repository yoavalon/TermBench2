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

    verifyConsensus(): boolean {
        let current = this.head;
        while (current) {
            if (!this.isValid(current.value)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    isValid(value: number): boolean {
        return value % 2 === 0;
    }
}

class ConsensusMechanism {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    run(): void {
        while (true) {
            if (!this.ledger.verifyConsensus()) {
                this.correctMutation();
            }
            this.ledger.append(this.generateNewValue());
        }
    }

    correctMutation(): void {
        let current = this.ledger.head;
        while (current) {
            if (!this.ledger.isValid(current.value)) {
                current.value = this.correctValue(current.value);
            }
            current = current.next;
        }
    }

    generateNewValue(): number {
        return Math.floor(Math.random() * 101);
    }

    correctValue(value: number): number {
        return value % 2 !== 0 ? value + 1 : value;
    }
}

function main(): void {
    const ledger = new Ledger();
    const mechanism = new ConsensusMechanism(ledger);
    mechanism.run();
}

main();