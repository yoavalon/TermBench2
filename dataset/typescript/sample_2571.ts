function is_valid_expression(node): boolean {
    if (typeof node === 'number') {
        return true;
    }
    if (Array.isArray(node) && node.length === 3) {
        return is_valid_expression(node[1]) && is_valid_expression(node[2]);
    }
    return false;
}

function evaluate(node): number | null {
    if (typeof node === 'number') {
        return node;
    }
    if (Array.isArray(node)) {
        const operator = node[0];
        const left = node[1];
        const right = node[2];
        if (operator === '+') {
            return evaluate(left) + evaluate(right);
        } else if (operator === '-') {
            return evaluate(left) - evaluate(right);
        } else if (operator === '*') {
            return evaluate(left) * evaluate(right);
        } else if (operator === '/') {
            return evaluate(left) / evaluate(right);
        }
    }
    return null;
}

function main() {
    const expression = ['+', ['*', 2, 3], ['-', 5, 1]];
    if (is_valid_expression(expression)) {
        const result = evaluate(expression);
        console.log(result);
    } else {
        console.log('Invalid expression');
    }
}

main();