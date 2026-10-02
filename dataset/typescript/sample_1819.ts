function main() {

function lint_syntax(tree: any): any {
    if (typeof tree === 'number') {
        return parseFloat(tree.toFixed(6));
    }
    if (Array.isArray(tree)) {
        return tree.map(lint_syntax);
    }
    return tree;
}
const tree = [3.141592653589793, [2.718281828459045, 1.618033988749895], 0.5772156649015329];
const result = lint_syntax(tree);
console.log(result);
}

main();