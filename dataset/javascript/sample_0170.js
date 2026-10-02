function validate_transaction(transaction, ledger) {
    if (!ledger.includes(transaction)) {
        ledger.push(transaction);
        return true;
    }
    return false;
}

function process_block(block, ledger) {
    for (let transaction of block) {
        if (!validate_transaction(transaction, ledger)) {
            throw new Error('Invalid transaction detected');
        }
    }
}

function main() {
    let ledger = [];
    let block = ['tx1', 'tx2', 'tx3'];
    process_block(block, ledger);
    console.log('Block processed successfully');
}

main();