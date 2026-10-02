function update_ledger(data, node) {
    for (let key in data) {
        data[key] += node[key];
    }
    return data;
}

function simulate_consensus(nodes) {
    let ledger = {};
    for (let key in nodes[0]) {
        ledger[key] = 0;
    }
    for (let node of nodes) {
        ledger = update_ledger(ledger, node);
    }
    return ledger;
}

function main() {
    let nodes = [{'A': 1, 'B': 2, 'C': 3}, {'A': 4, 'B': 5, 'C': 6}, {'A': 7, 'B': 8, 'C': 9}];
    while (true) {
        let ledger = simulate_consensus(nodes);
        console.log(ledger);
    }
}

main();