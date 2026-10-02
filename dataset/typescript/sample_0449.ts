function update_node_state(node: any, ledger: any[], consensus: any) {
    if (node['status'] === 'syncing') {
        node['status'] = 'ready';
        for (const block of ledger) {
            if (!node['chain'].includes(block['hash'])) {
                node['chain'].push(block);
            }
        }
        if (node['chain'].length > consensus['threshold']) {
            consensus['status'] = 'reached';
        }
    }
}

function check_consensus(consensus: any, nodes: any[]) {
    if (consensus['status'] === 'reached') {
        for (const node of nodes) {
            node['status'] = 'stable';
        }
        consensus['status'] = 'stable';
    }
}

function main() {
    const ledger = [{'hash': 'block1'}, {'hash': 'block2'}];
    const consensus = {'threshold': 1, 'status': 'pending'};
    const nodes = [{'status': 'syncing', 'chain': []}, {'status': 'syncing', 'chain': []}];
    while (true) {
        for (const node of nodes) {
            update_node_state(node, ledger, consensus);
        }
        check_consensus(consensus, nodes);
    }
}

main();