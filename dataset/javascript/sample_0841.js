class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children ? children : [];
    }

    add_child(child) {
        this.children.push(child);
    }
}

function calculate_cost(node, current_cost = 0) {
    if (node.children.length === 0) {
        return current_cost + node.value;
    }
    let total_cost = current_cost + node.value;
    for (let child of node.children) {
        total_cost += calculate_cost(child, current_cost + node.value);
    }
    return total_cost;
}

function optimize_supply_chain(root) {
    if (root.children.length === 0) {
        return root.value;
    }
    let min_cost = Infinity;
    for (let child of root.children) {
        let cost = calculate_cost(child);
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

function main() {
    let root = new Node(10);
    let child1 = new Node(5);
    let child2 = new Node(15);
    let child3 = new Node(20);
    let child4 = new Node(25);
    child1.add_child(new Node(30));
    child1.add_child(new Node(35));
    child2.add_child(new Node(40));
    child3.add_child(new Node(45));
    child4.add_child(new Node(50));
    root.add_child(child1);
    root.add_child(child2);
    root.add_child(child3);
    root.add_child(child4);
    let optimal_cost = optimize_supply_chain(root);
    console.log(optimal_cost);
}

main();