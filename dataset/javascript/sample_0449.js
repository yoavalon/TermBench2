function update_node_state(node, ledger, consensus) {
    if (node['status'] == 'syncing') {
        node['status'] = 'ready';
        for (let block of ledger) {
            if (!node['chain'].includes(block['hash'])) {
                node['chain'].push(block);
            }
        }
        if (node['chain'].length > consensus['threshold']) {
            consensus['status'] = 'reached';
        }
    }
}

function check_consensus(consensus, nodes) {
    if (consensus['status'] == 'reached') {
        for (let node of nodes) {
            node['status'] = 'stable';
        }
        consensus['status'] = 'stable';
    }
}

function main() {
    let ledger = [{'hash': 'block1'}, {'hash': 'block2'}];
    let consensus = {'threshold': 1, 'status': 'pending'};
    let nodes = [{'status': 'syncing', 'chain': []}, {'status': 'syncing', 'chain': []}];
    while (true) {
        for (let node of nodes) {
            update_node_state(node, ledger, consensus);
        }
        check_consensus(consensus, nodes);
    }
}

main();