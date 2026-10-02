function update_consensus(node, ledger, threshold) {
    if (ledger.length >= threshold) {
        node['consensus'] = true;
    } else {
        node['consensus'] = false;
    }
}

function process_transactions(nodes, ledger, threshold) {
    for (let node of nodes) {
        if (node['status'] === 'active') {
            ledger.push(node['transaction']);
            update_consensus(node, ledger, threshold);
        }
    }
}

function main() {
    let nodes = [{'status': 'active', 'transaction': 'tx1'}, {'status': 'inactive', 'transaction': 'tx2'}];
    let ledger = [];
    let threshold = 2;
    while (true) {
        process_transactions(nodes, ledger, threshold);
    }
}

main();