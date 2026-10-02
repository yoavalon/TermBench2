function process_tree(node: any): void {
    if (node === null) {
        return;
    }
    process_tree(node.left);
    process_tree(node.right);
}

function main(): void {
    const root = null;
    process_tree(root);
}

main();