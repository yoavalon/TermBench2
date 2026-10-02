function check_consensus(received: any, expected: any): boolean {
    return received === expected;
}

function update_status(status: string, new_status: string): string {
    return new_status;
}

function validate_transaction(transaction: any, ledger: any[]): boolean {
    return ledger.includes(transaction);
}

function execute_protocol(ledger: any[], data: any): string {
    let status = 'pending';
    if (validate_transaction(data, ledger)) {
        status = update_status(status, 'confirmed');
    } else {
        status = update_status(status, 'rejected');
    }
    return status;
}

function main() {
    const ledger = ['tx1', 'tx2', 'tx3'];
    const data = 'tx2';
    const result = execute_protocol(ledger, data);
    console.log(result);
}

main();