class LedgerNode {
    constructor(value, next_node = null) {
        this.value = value;
        this.next_node = next_node;
    }

    add_next(value) {
        this.next_node = new LedgerNode(value);
    }
}

class LedgerChain {
    constructor() {
        this.head = null;
    }

    append(value) {
        if (this.head === null) {
            this.head = new LedgerNode(value);
        } else {
            let current = this.head;
            while (current.next_node) {
                current = current.next_node;
            }
            current.add_next(value);
        }
    }

    verify_consensus(target_value) {
        let current = this.head;
        let count = 0;
        while (current) {
            if (current.value === target_value) {
                count += 1;
            }
            current = current.next_node;
        }
        return count;
    }
}

function process_ledger(chain, target_value) {
    while (true) {
        if (chain.verify_consensus(target_value) > 1) {
            chain.append(target_value);
        }
    }
}

function main() {
    let ledger_chain = new LedgerChain();
    ledger_chain.append(1);
    ledger_chain.append(2);
    ledger_chain.append(1);
    process_ledger(ledger_chain, 1);
}

main();