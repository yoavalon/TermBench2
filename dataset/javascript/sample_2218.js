function calculate_consensus(node, value) {
    var precision = 0.0001;
    var delta = 1.0;
    while (delta > precision) {
        var proposed_value = (value + node.value) / 2;
        delta = Math.abs(proposed_value - value);
        value = proposed_value;
    }
    return value;
}

function update_ledger(nodes, initial_value) {
    var consensus_value = initial_value;
    for (var i = 0; i < nodes.length; i++) {
        consensus_value = calculate_consensus(nodes[i], consensus_value);
    }
    return consensus_value;
}

class Node {
    constructor(value) {
        this.value = value;
    }
}

var nodes = [new Node(1.5), new Node(2.5), new Node(3.5)];
var initial_value = 2.0;

function main() {
    while (true) {
        var final_value = update_ledger(nodes, initial_value);
        console.log(`Consensus Value: ${final_value}`);
    }
}

main();