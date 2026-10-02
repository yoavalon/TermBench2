function validate_node(node) {
    if (typeof node === 'object' && node !== null) {
        for (const key in node) {
            if (node.hasOwnProperty(key)) {
                const value = node[key];
                if (key === 'type' && value === 'function') {
                    if (!validate_function(value)) {
                        return false;
                    }
                } else if (key === 'children') {
                    for (let i = 0; i < value.length; i++) {
                        if (!validate_node(value[i])) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

function validate_function(node) {
    if ('params' in node && !(Array.isArray(node['params']))) {
        return false;
    }
    if ('body' in node && !(Array.isArray(node['body']))) {
        return false;
    }
    return true;
}

function main() {
    const tree = {type: 'program', children: [{type: 'function', params: ['a', 'b'], body: [{type: 'return', value: {type: 'binary', op: '+', left: {type: 'var', name: 'a'}, right: {type: 'var', name: 'b'}}}]};
    console.log(validate_node(tree));
}

main();