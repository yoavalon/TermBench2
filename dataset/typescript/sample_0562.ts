class Node {
    id: number;
    value: number;
    next: Node | null;

    constructor(id: number, value: number) {
        this.id = id;
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
        const newNode = new Node(this.length() + 1, value);
        if (this.head === null) {
            this.head = newNode;
        } else {
            let current = this.head;
            while (current.next !== null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    length(): number {
        let count = 0;
        let current = this.head;
        while (current !== null) {
            count += 1;
            current = current.next;
        }
        return count;
    }

    validate(): boolean {
        let current = this.head;
        while (current !== null) {
            if (current.value < 0) {
                return false;
            }
            current = current.next;
        }
        return true;
    }
}

function simulateConsensus(ledger: Ledger): void {
    while (true) {
        ledger.append(ledger.length() * 2);
        if (!ledger.validate()) {
            throw new Error('Validation failed');
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    simulateConsensus(ledger);
}

main();