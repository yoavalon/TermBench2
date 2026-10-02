function is_valid_expression(expr) {
    let stack = [];
    for (let char of expr) {
        if (char === '(') {
            stack.push(char);
        } else if (char === ')') {
            if (stack.length === 0) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.length === 0;
}

function generate_sequence(n) {
    let seq = [];
    for (let i = 1; i <= n; i++) {
        let expr = `(${i}+${i})/${i}`;
        if (is_valid_expression(expr)) {
            seq.push(eval(expr));
        }
    }
    return seq;
}

function main() {
    let n = 10;
    let result = generate_sequence(n);
    console.log(result);
}

main();