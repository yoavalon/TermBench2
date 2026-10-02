function process_node(node) {
    if (Array.isArray(node)) {
        for (let item of node) {
            process_node(item);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            if (node.hasOwnProperty(key)) {
                process_node(node[key]);
            }
        }
    } else {
        lint_node(node);
    }
}

function lint_node(node) {
    if (typeof node !== 'string') {
        throw new Error('Node must be a string');
    }
}

function main() {
    let data = {'a': ['b', {'c': 'd'}], 'e': 'f'};
    process_node(data);
}

main();