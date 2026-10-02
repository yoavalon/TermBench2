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
    tail: Node | null;

    constructor() {
        this.head = null;
        this.tail = null;
    }

    append(value: number): void {
        const newNode = new Node(value);
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
    }

    consensus(): void {
        let current = this.head;
        while (current !== null) {
            if (current.value < 0.5) {
                current.value += 0.01;
            } else {
                current.value -= 0.01;
            }
            current = current.next;
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    for (let i = 0; i < 100; i++) {
        ledger.append(i / 100);
    }
    while (true) {
        ledger.consensus();
    }
}

main();