function lintSyntaxTree(tree: string[]): boolean {
    const stack: string[] = [];
    for (const node of tree) {
        if (node === 'open') {
            stack.push(node);
        } else if (node === 'close') {
            if (stack.length > 0 && stack[stack.length - 1] === 'open') {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.length === 0;
}

const exampleTree = ['open', 'open', 'close', 'close'];
console.log(lintSyntaxTree(exampleTree));