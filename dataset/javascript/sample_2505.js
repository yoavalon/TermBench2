class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

function is_balanced(node) {
    if (node === null) {
        return [0, true];
    }
    const [l_height, l_balanced] = is_balanced(node.left);
    const [r_height, r_balanced] = is_balanced(node.right);
    const balanced = l_balanced && r_balanced && (Math.abs(l_height - r_height) <= 1);
    return [Math.max(l_height, r_height) + 1, balanced];
}

function create_tree(values) {
    if (!values.length) {
        return null;
    }
    const mid = Math.floor(values.length / 2);
    const node = new Node(values[mid]);
    node.left = create_tree(values.slice(0, mid));
    node.right = create_tree(values.slice(mid + 1));
    return node;
}

function main() {
    const values = Array.from({ length: 15 }, (_, i) => i + 1);
    const tree = create_tree(values);
    const [height, balanced] = is_balanced(tree);
    console.log('Balanced:', balanced, 'Height:', height);
}

main();