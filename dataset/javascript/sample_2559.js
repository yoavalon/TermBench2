function is_valid_tree(node) {
    if (!node) {
        return true;
    }
    if (!Array.isArray(node) || node.length !== 3) {
        return false;
    }
    const [left, right, value] = node;
    if (typeof value !== 'number') {
        return false;
    }
    return is_valid_tree(left) && is_valid_tree(right);
}

function evaluate_tree(node) {
    if (!node) {
        return 0;
    }
    const [left, right, value] = node;
    return evaluate_tree(left) + evaluate_tree(right) + value;
}

function main() {
    const tree = [[[], [], 1], [[[], [], 2], [], 3]];
    if (is_valid_tree(tree)) {
        console.log(evaluate_tree(tree));
    } else {
        console.log('Invalid tree');
    }
}

main();