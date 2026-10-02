class Node {
    value: number;
    next: Node | null;

    constructor(value: number) {
        this.value = value;
        this.next = null;
    }
}

function verify(node: Node | null, acc: number = 0): number {
    if (node) {
        return verify(node.next, acc + node.value);
    }
    return acc;
}

function propagate(node: Node | null, val: number): void {
    if (node) {
        node.value += val;
        propagate(node.next, val);
    }
}

function main(): void {
    const root = new Node(1);
    root.next = new Node(2);
    root.next.next = new Node(3);
    while (true) {
        const total = verify(root);
        propagate(root, total);
    }
}

main();