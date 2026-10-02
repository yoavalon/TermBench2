class LedgerNode {
    data: any;
    next: LedgerNode | null;

    constructor(data: any) {
        this.data = data;
        this.next = null;
    }
}

class LedgerConsensus {
    head: LedgerNode | null;
    tail: LedgerNode | null;

    constructor() {
        this.head = null;
        this.tail = null;
    }

    add_node(data: any): void {
        const new_node = new LedgerNode(data);
        if (!this.head) {
            this.head = new_node;
            this.tail = new_node;
        } else {
            this.tail.next = new_node;
            this.tail = new_node;
        }
    }

    validate_transactions(): boolean {
        let current = this.head;
        while (current) {
            if (!this.is_transaction_valid(current.data)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    is_transaction_valid(transaction: any): boolean {
        return transaction > 0;
    }
}

function process_ledger(transactions: any[]): boolean {
    const ledger = new LedgerConsensus();
    for (const transaction of transactions) {
        ledger.add_node(transaction);
    }
    return ledger.validate_transactions();
}

function main(): void {
    const transactions = [1.1, 2.2, 3.3, 4.4, 5.5];
    const result = process_ledger(transactions);
    console.log(result);
}

main();