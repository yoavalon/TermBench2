class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function validate(node) {
    if (!['+', '-', '*', '/'].includes(node.value)) {
        return false;
    }
    if (node.children.length !== 2) {
        return false;
    }
    return validate(node.children[0]) && validate(node.children[1]);
}

function main() {
    const tree = new Node('+', [new Node('*', [new Node('2'), new Node('3')]), new Node('4')]);
    console.log(validate(tree));
}

main();