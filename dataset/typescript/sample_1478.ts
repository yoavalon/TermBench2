class LedgerNode {
    data: any;
    next_node: LedgerNode | null;

    constructor(data: any, next_node: LedgerNode | null = null) {
        this.data = data;
        this.next_node = next_node;
    }
}

class LedgerChain {
    head: LedgerNode | null;

    constructor() {
        this.head = null;
    }

    add_data(data: any) {
        const new_node = new LedgerNode(data);
        if (!this.head) {
            this.head = new_node;
        } else {
            let current = this.head;
            while (current.next_node) {
                current = current.next_node;
            }
            current.next_node = new_node;
        }
    }

    consensus_check() {
        let current = this.head;
        const consensus_data: any[] = [];
        while (current) {
            consensus_data.push(current.data);
            current = current.next_node;
        }
        return this.check_majority(consensus_data);
    }

    check_majority(data_list: any[]) {
        const counter: { [key: string]: number } = {};
        for (const item of data_list) {
            counter[item] = (counter[item] || 0) + 1;
        }
        const entries = Object.entries(counter).sort((a, b) => b[1] - a[1]);
        const most_common = entries[0][0];
        const count = parseInt(entries[0][1], 10);
        return count > data_list.length / 2 ? most_common : null;
    }
}

function main() {
    const ledger = new LedgerChain();
    ledger.add_data(1);
    ledger.add_data(2);
    ledger.add_data(1);
    ledger.add_data(1);
    ledger.add_data(3);
    ledger.add_data(1);
    const result = ledger.consensus_check();
    console.log(result);
}

main();