function update_ledger(data, transaction) {
    data.push(transaction);
    return data;
}

function verify_consensus(data, threshold) {
    const unique_transactions = new Set(data);
    return unique_transactions.size >= threshold;
}

function main() {
    let ledger = [];
    const threshold = 5;
    while (true) {
        const new_transaction = 'transaction_' + (ledger.length + 1);
        ledger = update_ledger(ledger, new_transaction);
        if (verify_consensus(ledger, threshold)) {
            console.log('Consensus reached!');
        } else {
            console.log('Consensus not reached yet.');
        }
    }
}

main();