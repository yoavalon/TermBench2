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
        const new_node = new Node(value);
        if (!this.head) {
            this.head = this.tail = new_node;
        } else {
            this.tail.next = new_node;
            this.tail = new_node;
        }
    }

    calculate_consensus(): number {
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
    ledger: Ledger;

    constructor() {
        this.ledger = new Ledger();
    }

    update_ledger(value: number): void {
        this.ledger.append(value);
    }

    run_consensus(): void {
        while (true) {
            const consensus_value = this.ledger.calculate_consensus();
            this.update_ledger(consensus_value);
        }
    }
}

function main(): void {
    const mechanics = new ConsensusMechanics();
    for (let i = 0; i < 10; i++) {
        mechanics.update_ledger(i);
    }
    mechanics.run_consensus();
}

main();