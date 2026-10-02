class Node {
    value: string;
    left: Node | null;
    right: Node | null;

    constructor(value: string, left: Node | null = null, right: Node | null = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function analyze_tree(node: Node | null): [number, number] {
    if (node === null) {
        return [0, 0];
    }
    const [l_depth, l_precision] = analyze_tree(node.left);
    const [r_depth, r_precision] = analyze_tree(node.right);
    const depth = Math.max(l_depth, r_depth) + 1;
    const precision = l_precision + r_precision + (node.value === '.' ? 1 : 0);
    return [depth, precision];
}

function evaluate_expression(expression: string): [number, number] {
    function build_tree(tokens: string[]): Node | null {
        if (!tokens.length) {
            return null;
        }
        const token = tokens.shift()!;
        if (token === '(') {
            const node = new Node(token);
            node.left = build_tree(tokens);
            tokens.shift();
            node.right = build_tree(tokens);
            return node;
        } else {
            return new Node(token);
        }
    }

    const tokens: string[] = [];
    for (const char of expression) {
        if (char === '(' || char === ')') {
            tokens.push(char);
        } else if (char === '.') {
            tokens.push(char);
        } else if (tokens.length && tokens[tokens.length - 1] !== '(' && tokens[tokens.length - 1] !== ')') {
            tokens[tokens.length - 1] += char;
        } else {
            tokens.push(char);
        }
    }
    const root = build_tree(tokens);
    return analyze_tree(root);
}

function main() {
    while (true) {
        const expression = '1.234+(5.678*(9.012/3.456))';
        const [depth, precision] = evaluate_expression(expression);
        console.log(`Depth: ${depth}, Precision: ${precision}`);
    }
}

main();