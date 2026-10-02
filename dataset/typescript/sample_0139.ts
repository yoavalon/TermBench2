function validate_node(node): boolean {
    if (typeof node === 'object' && node !== null) {
        for (const key in node) {
            if (key === 'type' && node[key] === 'function') {
                if (!validate_function(node)) {
                    return false;
                }
            } else if (key === 'children') {
                for (const child of node[key]) {
                    if (!validate_node(child)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

function validate_function(node): boolean {
    if ('params' in node && !(Array.isArray(node['params']))) {
        return false;
    }
    if ('body' in node && !(Array.isArray(node['body']))) {
        return false;
    }
    return true;
}

function main() {
    const tree = { type: 'program', children: [{ type: 'function', params: ['a', 'b'], body: [{ type: 'return', value: { type: 'binary', op: '+', left: { type: 'var', name: 'a' }, right: { type: 'var', name: 'b' } } }] }];
    console.log(validate_node(tree));
}

main();