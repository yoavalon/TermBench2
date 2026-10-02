function update_consensus(node: { consensus: boolean }, ledger: any[], threshold: number): void {
    if (ledger.length >= threshold) {
        node.consensus = true;
    } else {
        node.consensus = false;
    }
}

function process_transactions(nodes: { status: string, transaction: any }[], ledger: any[], threshold: number): void {
    for (const node of nodes) {
        if (node.status === 'active') {
            ledger.push(node.transaction);
            update_consensus(node, ledger, threshold);
        }
    }
}

function main(): void {
    const nodes = [{ status: 'active', transaction: 'tx1' }, { status: 'inactive', transaction: 'tx2' }];
    const ledger: any[] = [];
    const threshold = 2;
    while (true) {
        process_transactions(nodes, ledger, threshold);
    }
}

main();