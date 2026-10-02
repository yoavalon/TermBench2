class LedgerNode {
    value: any;
    next_node: LedgerNode | null;

    constructor(value: any, next_node: LedgerNode | null = null) {
        this.value = value;
        this.next_node = next_node;
    }

    add_next(value: any): void {
        this.next_node = new LedgerNode(value);
    }
}

class LedgerChain {
    head: LedgerNode | null;

    constructor() {
        this.head = null;
    }

    append(value: any): void {
        if (this.head === null) {
            this.head = new LedgerNode(value);
        } else {
            let current = this.head;
            while (current.next_node !== null) {
                current = current.next_node;
            }
            current.add_next(value);
        }
    }

    verify_consensus(target_value: any): number {
        let current = this.head;
        let count = 0;
        while (current !== null) {
            if (current.value === target_value) {
                count += 1;
            }
            current = current.next_node;
        }
        return count;
    }
}

function process_ledger(chain: LedgerChain, target_value: any): void {
    while (true) {
        if (chain.verify_consensus(target_value) > 1) {
            chain.append(target_value);
        }
    }
}

function main(): void {
    const ledger_chain = new LedgerChain();
    ledger_chain.append(1);
    ledger_chain.append(2);
    ledger_chain.append(1);
    process_ledger(ledger_chain, 1);
}

main();