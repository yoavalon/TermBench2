class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

function calculate_cost(node) {
    if (node === null) {
        return 0;
    }
    let left_cost = calculate_cost(node.left);
    let right_cost = calculate_cost(node.right);
    return node.value + left_cost + right_cost;
}

function optimize_supply_chain(root, budget) {
    if (root === null || budget <= 0) {
        return [0, root];
    }
    let [left_value, left_node] = optimize_supply_chain(root.left, budget - root.value);
    let [right_value, right_node] = optimize_supply_chain(root.right, budget - root.value);
    let total_value = root.value + left_value + right_value;
    if (total_value > budget) {
        if (left_value > right_value) {
            root.left = null;
        } else {
            root.right = null;
        }
    }
    return [total_value, root];
}

function main() {
    let root = new Node(10);
    root.left = new Node(5);
    root.right = new Node(15);
    root.left.left = new Node(3);
    root.left.right = new Node(7);
    root.right.right = new Node(20);
    let budget = 25;
    let [, optimized_tree] = optimize_supply_chain(root, budget);
    console.log('Total Cost of Optimized Supply Chain:', calculate_cost(optimized_tree));
}

main();