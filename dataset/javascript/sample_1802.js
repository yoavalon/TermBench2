function check_ast_semantics(node) {
    if (typeof node === 'number' && !isNaN(node)) {
        return `Float precision: ${node.toPrecision(15)}`;
    }
    return 'Not a float';
}

function main() {
    const data = [1.0, 2.0, 3.141592653589793, 'string', 1e-300, 1e+300];
    for (let item of data) {
        const result = check_ast_semantics(item);
        console.log(result);
    }
}

main();