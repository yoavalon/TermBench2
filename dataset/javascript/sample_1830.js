function lint_ast(node) {
    if (typeof node === 'number') {
        return node.toString();
    } else if (Array.isArray(node)) {
        return node.map(x => lint_ast(x));
    } else {
        return node;
    }
}

function main() {
    const test_data = [1.0, [2.0, 3.0], 4.0, [5.0, [6.0, 7.0]], 8.0];
    const result = lint_ast(test_data);
    console.log(result);
}

main();