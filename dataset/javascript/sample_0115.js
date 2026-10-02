function check_consensus(received, expected) {
    return received === expected;
}

function update_status(status, new_status) {
    return new_status;
}

function validate_transaction(transaction, ledger) {
    return ledger.includes(transaction);
}

function execute_protocol(ledger, data) {
    let status = 'pending';
    if (validate_transaction(data, ledger)) {
        status = update_status(status, 'confirmed');
    } else {
        status = update_status(status, 'rejected');
    }
    return status;
}

function main() {
    let ledger = ['tx1', 'tx2', 'tx3'];
    let data = 'tx2';
    let result = execute_protocol(ledger, data);
    console.log(result);
}

main();