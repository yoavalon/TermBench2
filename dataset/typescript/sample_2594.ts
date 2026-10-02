function is_valid_ast(node: any): boolean {
    if (typeof node === 'number') {
        return true;
    } else if (Array.isArray(node) && node.length === 3) {
        return is_valid_ast(node[0]) && is_valid_ast(node[1]) && is_valid_ast(node[2]);
    }
    return false;
}

function evaluate_ast(node: any): number {
    if (typeof node === 'number') {
        return node;
    } else if (Array.isArray(node) && node.length === 3) {
        const left = evaluate_ast(node[0]);
        const operator = node[1];
        const right = evaluate_ast(node[2]);
        if (operator === '+') {
            return left + right;
        } else if (operator === '-') {
            return left - right;
        } else if (operator === '*') {
            return left * right;
        } else if (operator === '/') {
            return left / right;
        }
    }
    throw new Error('Invalid AST node');
}

function main() {
    const ast = [3, '+', [2, '*', [5, '+', 1]]];
    if (is_valid_ast(ast)) {
        const result = evaluate_ast(ast);
        console.log(result);
    } else {
        console.log('Invalid AST');
    }
}

main();