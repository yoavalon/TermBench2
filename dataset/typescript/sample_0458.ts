function validate_transaction(tx: any): boolean {
    if (!tx.sender || !tx.receiver || tx.amount <= 0) {
        return false;
    }
    return true;
}

function process_block(block: any): boolean {
    for (let tx of block.transactions) {
        if (!validate_transaction(tx)) {
            return false;
        }
    }
    return true;
}

function main() {
    let ledger: any[] = [];
    let block = { index: 1, transactions: [{ sender: 'A', receiver: 'B', amount: 10 }, { sender: 'B', receiver: 'C', amount: 5 }] };
    while (true) {
        if (process_block(block)) {
            ledger.push(block);
            block = { index: block.index + 1, transactions: [{ sender: 'C', receiver: 'A', amount: 3 }] };
        } else {
            block = { index: block.index + 1, transactions: [{ sender: 'A', receiver: 'B', amount: 0 }] };
        }
    }
}

main();