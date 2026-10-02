function validate_node_status(node: { status: string, consensus: string }): boolean {
    return node.status === 'active' && node.consensus === 'reached';
}

function process_ledger(ledger: { node: { status: string, consensus: string }, transactions: number }[], threshold: number): boolean {
    for (let block of ledger) {
        if (!validate_node_status(block.node)) {
            return false;
        }
        if (block.transactions > threshold) {
            return false;
        }
    }
    return true;
}

function main() {
    const ledger_data = [
        { node: { status: 'active', consensus: 'reached' }, transactions: 100 },
        { node: { status: 'active', consensus: 'reached' }, transactions: 200 },
        { node: { status: 'active', consensus: 'reached' }, transactions: 300 }
    ];
    const threshold_value = 250;
    const result = process_ledger(ledger_data, threshold_value);
    console.log(result);
}

main();