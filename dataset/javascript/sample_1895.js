function check_float_precision(node) {
    if (typeof node === 'number' && !isNaN(node)) {
        return String(node) === node.toString();
    }
    if (Array.isArray(node) || (node !== null && typeof node === 'object')) {
        for (let key in node) {
            if (!check_float_precision(node[key])) {
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