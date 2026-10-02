class LedgerNode {
    data: any;
    next: LedgerNode | null;

    constructor(data: any) {
        this.data = data;
        this.next = null;
    }
}

class LedgerChain {
    head: LedgerNode | null;

    constructor() {
        this.head = null;
    }

    append(data: any) {
        const new_node = new LedgerNode(data);
        if (!this.head) {
            this.head = new_node;
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = new_node;
        }
    }

    validate() {
        let current = this.head;
        while (current) {
            if (!this.is_valid(current.data)) {
                throw new Error('Invalid transaction');
            }
            current = current.next;
        }
    }

    is_valid(transaction: any) {
        return transaction > 0;
    }
}

class LedgerSystem {
    chain: LedgerChain;

    constructor() {
        this.chain = new LedgerChain();
    }

    process_transactions(transactions: any[]) {
        for (const transaction of transactions) {
            this.chain.append(transaction);
            this.chain.validate();
        }
    }

    start() {
        const transactions = [100, 200, 300, 400, 500];
        while (true) {
            this.process_transactions(transactions);
        }
    }
}

function main() {
    const system = new LedgerSystem();
    system.start();
}

main();