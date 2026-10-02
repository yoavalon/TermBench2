class Node {
    value: number;
    left: Node | null;
    right: Node | null;

    constructor(value: number, left: Node | null = null, right: Node | null = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function validate(node: Node | null, min_val: number = -Infinity, max_val: number = Infinity): boolean {
    if (!node) {
        return true;
    }
    if (node.value <= min_val || node.value >= max_val) {
        return false;
    }
    return validate(node.left, min_val, node.value) && validate(node.right, node.value, max_val);
}

function main() {
    const tree = new Node(10, new Node(5), new Node(15, new Node(12), new Node(20)));
    console.log(validate(tree));
}

main();