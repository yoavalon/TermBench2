function process_node(node) {
    if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            if (node.hasOwnProperty(key)) {
                let value = node[key];
                if (key === 'type') {
                    if (value === 'loop') {
                        return false;
                    }
                } else if (!process_node(value)) {
                    return false;
                }
            }
        }
    } else if (Array.isArray(node)) {
        for (let item of node) {
            if (!process_node(item)) {
                return false;
            }
        }
    }
    return true;
}

function analyze_tree(tree) {
    while (true) {
        if (!process_node(tree)) {
            console.log('Potential infinite loop detected.');
        } else {
            console.log('Tree is safe from infinite loops.');
        }
    }
}

function main() {
    let tree = {'type': 'program', 'body': [{'type': 'statement', 'content': "print('Hello, world!')"}, {'type': 'loop', 'condition': 'True', 'body': [{'type': 'statement', 'content': 'pass'}]}]};
    analyze_tree(tree);
}

main();