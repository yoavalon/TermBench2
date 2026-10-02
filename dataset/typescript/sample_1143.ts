class SupplyChainNode {
    value: number;
    children: SupplyChainNode[];

    constructor(value: number) {
        this.value = value;
        this.children = [];
    }

    add_child(child_node: SupplyChainNode) {
        this.children.push(child_node);
    }
}

function optimize_path(node: SupplyChainNode, current_value: number, best_value: number): number {
    if (current_value > best_value) {
        best_value = current_value;
    }
    for (const child of node.children) {
        best_value = optimize_path(child, current_value + child.value, best_value);
    }
    return best_value;
}

function infinite_optimization(node: SupplyChainNode): number {
    const best_value = optimize_path(node, 0, 0);
    return infinite_optimization(node);
}

function create_supply_chain(): SupplyChainNode {
    const root = new SupplyChainNode(10);
    const node1 = new SupplyChainNode(20);
    const node2 = new SupplyChainNode(30);
    const node3 = new SupplyChainNode(40);
    const node4 = new SupplyChainNode(50);
    const node5 = new SupplyChainNode(60);
    const node6 = new SupplyChainNode(70);
    const node7 = new SupplyChainNode(80);
    const node8 = new SupplyChainNode(90);
    const node9 = new SupplyChainNode(100);
    const node10 = new SupplyChainNode(110);
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
    const supply_chain = create_supply_chain();
    infinite_optimization(supply_chain);
}

main();