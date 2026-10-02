class Node {
    value: string;
    children: Node[];

    constructor(value: string) {
        this.value = value;
        this.children = [];
    }

    add_child(child: Node) {
        this.children.push(child);
    }
}

class Tree {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }

    validate() {
        const check = (node: Node) => {
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

function parse(data: string[]): Tree {
    const root = new Node('start');
    let current = root;
    const stack: Node[] = [];
    for (const item of data) {
        if (item === '(') {
            stack.push(current);
            current.add_child(new Node('block'));
            current = current.children[current.children.length - 1];
        } else if (item === ')') {
            current = stack.pop()!;
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
        console.error(e.message);
    }
}

main();