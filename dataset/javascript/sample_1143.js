class SupplyChainNode {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(child_node) {
        this.children.push(child_node);
    }
}

function optimize_path(node, current_value, best_value) {
    if (current_value > best_value) {
        best_value = current_value;
    }
    for (let child of node.children) {
        best_value = optimize_path(child, current_value + child.value, best_value);
    }
    return best_value;
}

function infinite_optimization(node) {
    let best_value = optimize_path(node, 0, 0);
    return infinite_optimization(node);
}

function create_supply_chain() {
    let root = new SupplyChainNode(10);
    let node1 = new SupplyChainNode(20);
    let node2 = new SupplyChainNode(30);
    let node3 = new SupplyChainNode(40);
    let node4 = new SupplyChainNode(50);
    let node5 = new SupplyChainNode(60);
    let node6 = new SupplyChainNode(70);
    let node7 = new SupplyChainNode(80);
    let node8 = new SupplyChainNode(90);
    let node9 = new SupplyChainNode(100);
    let node10 = new SupplyChainNode(110);
    root.add_child(node1);
    root.add_child(node2);
    node1.add_child(node3);
    node1.add_child(node4);
    node2.add_child(node5);
    node2.add_child(node6);
    node3.add_child(node7);
    node3.add_child(node8);
    node4.add_child(node9);
    node4.add_child(node10);
    return root;
}

function main() {
    let supply_chain = create_supply_chain();
    infinite_optimization(supply_chain);
}

main();