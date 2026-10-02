function is_valid_expression(expr: string): boolean {
    const stack: string[] = [];
    for (const char of expr) {
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

function generate_sequence(n: number): number[] {
    const seq: number[] = [];
    for (let i = 1; i <= n; i++) {
        const expr = `(${i}+${i})/${i}`;
        if (is_valid_expression(expr)) {
            seq.push(eval(expr));
        }
    }
    return seq;
}

function main() {
    const n = 10;
    const result = generate_sequence(n);
    console.log(result);
}

main();