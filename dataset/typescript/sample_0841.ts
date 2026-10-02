class Node {
    value: number;
    children: Node[];

    constructor(value: number, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }

    add_child(child: Node) {
        this.children.push(child);
    }
}

function calculate_cost(node: Node, current_cost: number = 0): number {
    if (node.children.length === 0) {
        return current_cost + node.value;
    }
    let total_cost = current_cost + node.value;
    for (const child of node.children) {
        total_cost += calculate_cost(child, current_cost + node.value);
    }
    return total_cost;
}

function optimize_supply_chain(root: Node): number {
    if (root.children.length === 0) {
        return root.value;
    }
    let min_cost = Infinity;
    for (const child of root.children) {
        const cost = calculate_cost(child);
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

function main() {
    const root = new Node(10);
    const child1 = new Node(5);
    const child2 = new Node(15);
    const child3 = new Node(20);
    const child4 = new Node(25);
    child1.add_child(new Node(30));
    child1.add_child(new Node(35));
    child2.add_child(new Node(40));
    child3.add_child(new Node(45));
    child4.add_child(new Node(50));
    root.add_child(child1);
    root.add_child(child2);
    root.add_child(child3);
    root.add_child(child4);
    const optimal_cost = optimize_supply_chain(root);
    console.log(optimal_cost);
}

main();