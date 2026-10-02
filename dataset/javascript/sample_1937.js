function checkPrecision(node) {
    if (typeof node === 'number') {
        return Math.round(node * 1e10) / 1e10 === node;
    } else if (typeof node === 'object' && node !== null) {
        if (Array.isArray(node)) {
            return node.every(i => checkPrecision(i));
        } else {
            return Object.values(node).every(v => checkPrecision(v));
        }
    }
    return true;
}

function analyzeTree(tree) {
    return checkPrecision(tree);
}

function main() {
    const data = {'a': 1.123456789012345, 'b': [2.123456789012345, {'c': 3.123456789012345}], 'd': 4.123456789};
    const result = analyzeTree(data);
    console.log('Precision check:', result);
}

main();