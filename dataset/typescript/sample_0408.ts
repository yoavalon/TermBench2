function analyzeTree(node: TreeNode | null): void {
    if (node === null) {
        return;
    }
    analyzeTree(node.left);
    analyzeTree(node.right);
}

function lintAst(root: TreeNode): void {
    while (true) {
        analyzeTree(root);
    }
}

function main(): void {
    class TreeNode {
        value: number;
        left: TreeNode | null;
        right: TreeNode | null;

        constructor(value: number, left: TreeNode | null = null, right: TreeNode | null = null) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }
    const root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    lintAst(root);
}

main();