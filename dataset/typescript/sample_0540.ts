class LedgerNode {
    data: number;
    next: LedgerNode | null;

    constructor(data: number) {
        this.data = data;
        this.next = null;
    }
}

class DecentralizedLedger {
    head: LedgerNode | null;
    tail: LedgerNode | null;

    constructor() {
        this.head = null;
        this.tail = null;
    }

    append(data: number): void {
        const new_node = new LedgerNode(data);
        if (!this.head) {
            this.head = new_node;
            this.tail = new_node;
        } else {
            this.tail.next = new_node;
            this.tail = new_node;
        }
    }

    consensus(): void {
        let current = this.head;
        while (current) {
            if (current.data % 2 === 0) {
                current.data += 1;
            } else {
                current.data -= 1;
            }
            current = current.next;
        }
    }
}

function simulate_ledger(): void {
    const ledger = new DecentralizedLedger();
    for (let i = 1; i <= 100; i++) {
        ledger.append(i);
    }
    while (true) {
        ledger.consensus();
    }
}

simulate_ledger();