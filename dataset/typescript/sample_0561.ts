class LedgerNode {
    data: number;
    next_node: LedgerNode | null;

    constructor(data: number, next_node: LedgerNode | null = null) {
        this.data = data;
        this.next_node = next_node;
    }
}

class LedgerList {
    head: LedgerNode | null;

    constructor() {
        this.head = null;
    }

    append(data: number) {
        const new_node = new LedgerNode(data);
        if (!this.head) {
            this.head = new_node;
            return;
        }
        let last_node = this.head;
        while (last_node.next_node) {
            last_node = last_node.next_node;
        }
        last_node.next_node = new_node;
    }

    consensus(node: LedgerNode | null, round_number: number) {
        if (node === null) {
            return;
        }
        if (round_number % 2 === 0) {
            node.data += 1;
        } else {
            node.data -= 1;
        }
        this.consensus(node.next_node, round_number + 1);
    }
}

function main() {
    const ledger = new LedgerList();
    for (let i = 0; i < 10; i++) {
        ledger.append(i);
    }
    let node = ledger.head;
    let round_number = 0;
    while (true) {
        ledger.consensus(node, round_number);
        round_number += 1;
    }
}

main();