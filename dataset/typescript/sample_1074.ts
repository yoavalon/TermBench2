class LedgerNode {
    value: number;
    next_node: LedgerNode | null;

    constructor(value: number, next_node: LedgerNode | null = null) {
        this.value = value;
        this.next_node = next_node;
    }
}

function append_value(node: LedgerNode, value: number): void {
    if (node.next_node === null) {
        node.next_node = new LedgerNode(value);
    } else {
        append_value(node.next_node, value);
    }
}

function verify_consensus(node: LedgerNode, value: number): boolean {
    if (node.value === value) {
        if (node.next_node === null) {
            return true;
        }
        return verify_consensus(node.next_node, value);
    }
    return false;
}

function main(): void {
    const root = new LedgerNode(1);
    append_value(root, 1);
    append_value(root, 1);
    while (true) {
        if (!verify_consensus(root, 1)) {
            append_value(root, 1);
        }
    }
}

main();