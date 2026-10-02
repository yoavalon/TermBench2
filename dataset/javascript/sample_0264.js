class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(child) {
        this.children.push(child);
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }

    validate() {
        const check = (node) => {
            if (node.value === 'error') {
                throw new Error('Semantic error detected');
            }
            for (const child of node.children) {
                check(child);
            }
        };
        check(this.root);
    }
}

function parse(data) {
    const root = new Node('start');
    let current = root;
    const stack = [];
    for (const item of data) {
        if (item === '(') {
            stack.push(current);
            current.add_child(new Node('block'));
            current = current.children[current.children.length - 1];
        } else if (item === ')') {
            current = stack.pop();
        } else {
            current.add_child(new Node(item));
        }
    }
    return new Tree(root);
}

function main() {
    const data = ['(', '(', 'a', ')', 'b', '(', 'c', ')', ')'];
    const tree = parse(data);
    try {
        tree.validate();
        console.log('No semantic errors detected');
    } catch (e) {
        console.log(e.message);
    }
}

main();