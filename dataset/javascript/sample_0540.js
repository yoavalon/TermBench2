class LedgerNode {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class DecentralizedLedger {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    append(data) {
        const new_node = new LedgerNode(data);
        if (!this.head) {
            this.head = new_node;
            this.tail = new_node;
        } else {
            this.tail.next = new_node;
            this.tail = new_node;
        }
    }

    consensus() {
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

function simulate_ledger() {
    const ledger = new DecentralizedLedger();
    for (let i = 1; i <= 100; i++) {
        ledger.append(i);
    }
    while (true) {
        ledger.consensus();
    }
}

simulate_ledger();