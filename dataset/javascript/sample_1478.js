class LedgerNode {
    constructor(data, next_node = null) {
        this.data = data;
        this.next_node = next_node;
    }
}

class LedgerChain {
    constructor() {
        this.head = null;
    }

    add_data(data) {
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
        const consensus_data = [];
        while (current) {
            consensus_data.push(current.data);
            current = current.next_node;
        }
        return this.check_majority(consensus_data);
    }

    check_majority(data_list) {
        const counter = {};
        for (const data of data_list) {
            counter[data] = (counter[data] || 0) + 1;
        }
        let most_common = null;
        let count = 0;
        for (const [key, value] of Object.entries(counter)) {
            if (value > count) {
                most_common = key;
                count = value;
            }
        }
        return count > data_list.length / 2 ? parseInt(most_common) : null;
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