function check_precision(node): boolean {
    if (typeof node === 'number') {
        return Math.round(node * 1e10) / 1e10 === node;
    } else if (typeof node === 'object' && node !== null) {
        if (Array.isArray(node)) {
            return node.every(i => check_precision(i));
        } else {
            return Object.values(node).every(v => check_precision(v));
        }
    }
    return true;
}

function analyze_tree(tree): boolean {
    return check_precision(tree);
}

function main() {
    const data = { a: 1.123456789012345, b: [2.123456789012345, { c: 3.123456789012345 }], d: 4.123456789 };
    const result = analyze_tree(data);
    console.log('Precision check:', result);
}

main();