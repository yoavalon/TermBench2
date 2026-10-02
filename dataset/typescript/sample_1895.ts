function check_float_precision(node: any): boolean {
    if (typeof node === 'number') {
        return node.toString() === node.toExponential();
    }
    if (Array.isArray(node) || typeof node === 'object') {
        for (const x of Object.values(node)) {
            if (!check_float_precision(x)) {
                return false;
            }
        }
        return true;
    }
    return true;
}

function main() {
    const data = { 'a': 1.1, 'b': [2.2, 3.3], 'c': { 'd': 4.4, 'e': [5.5, { 'f': 6.6 }] } };
    const result = check_float_precision(data);
    console.log(result);
}

main();