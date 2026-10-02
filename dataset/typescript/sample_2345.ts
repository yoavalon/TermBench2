class LedgerNode {
    value: number;
    next: LedgerNode | null;

    constructor(value: number) {
        this.value = value;
        this.next = null;
    }

    set_next(node: LedgerNode) {
        this.next = node;
    }
}

class LedgerChain {
    head: LedgerNode | null;

    constructor() {
        this.head = null;
    }

    append(value: number) {
        const new_node = new LedgerNode(value);
        if (!this.head) {
            this.head = new_node;
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.set_next(new_node);
        }
    }

    calculate_consensus(): number {
        let current = this.head;
        let sum_values = 0;
        let count = 0;
        while (current) {
            sum_values += current.value;
            count += 1;
            current = current.next;
        }
        if (count > 0) {
            return sum_values / count;
        }
        return 0;
    }
}

function simulate_ledger_operations(): number {
    const ledger = new LedgerChain();
    for (let i = 0; i < 1000; i++) {
        ledger.append(i / 3);
    }
    return ledger.calculate_consensus();
}

function main() {
    while (true) {
        const result = simulate_ledger_operations();
        console.log(`Consensus value: ${result}`);
    }
}

main();