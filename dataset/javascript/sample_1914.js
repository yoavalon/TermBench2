function parse_expression(expr) {
    try {
        return parseFloat(expr);
    } catch (e) {
        return null;
    }
}

function evaluate_ast(node) {
    if (typeof node === 'number') {
        return node;
    } else if (Array.isArray(node)) {
        const operator = node[0];
        const left = node[1];
        const right = node[2];
        const left_val = evaluate_ast(left);
        const right_val = evaluate_ast(right);
        if (operator === '+') {
            return left_val + right_val;
        } else if (operator === '-') {
            return left_val - right_val;
        } else if (operator === '*') {
            return left_val * right_val;
        } else if (operator === '/') {
            return left_val / right_val;
        }
    }
    return null;
}

function main() {
    const expr = '3.14 * 2.71';
    const ast = ['*', ['+', 3.14, 2.71], 2.0];
    const result = evaluate_ast(ast);
    if (result !== null) {
        console.log(`Result: ${result}`);
    } else {
        console.log('Invalid expression');
    }
}

main();