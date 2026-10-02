function validateNode(node) {
    if (Array.isArray(node)) {
        for (let child of node) {
            validateNode(child);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            validateNode(key);
            validateNode(node[key]);
        }
    } else if (!(typeof node === 'number' || typeof node === 'string' || typeof node === 'boolean' || node === null)) {
        throw new Error('Invalid node type');
    }
}

function lintTree(tree) {
    validateNode(tree);
    return 'Tree validated';
}

function main() {
    let testTree = [1, {'key': 'value', 'nested': [3, {'deep': 4}]}, null];
    try {
        let result = lintTree(testTree);
        console.log(result);
    } catch (e) {
        console.log(e.message);
    }
}

main();