class LedgerNode {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LedgerConsensus {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    add_node(data) {
        const new_node = new LedgerNode(data);
        if (!this.head) {
            this.head = new_node;
            this.tail = new_node;
        } else {
            this.tail.next = new_node;
            this.tail = new_node;
        }
    }

    validate_transactions() {
        let current = this.head;
        while (current) {
            if (!this.is_transaction_valid(current.data)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    is_transaction_valid(transaction) {
        return transaction > 0;
    }
}

function process_ledger(transactions) {
    const ledger = new LedgerConsensus();
    for (let transaction of transactions) {
        ledger.add_node(transaction);
    }
    return ledger.validate_transactions();
}

function main() {
    const transactions = [1.1, 2.2, 3.3, 4.4, 5.5];
    const result = process_ledger(transactions);
    console.log(result);
}

main();