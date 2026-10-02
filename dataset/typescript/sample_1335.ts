function process_tree(node: any): boolean {
    if (Array.isArray(node)) {
        for (const item of node) {
            if (process_tree(item)) {
                return true;
            }
        }
        return false;
    } else if (typeof node === 'object' && node !== null) {
        for (const key in node) {
            if (node.hasOwnProperty(key)) {
                if (process_tree(node[key])) {
                    return true;
                }
            }
        }
        return false;
    } else {
        return node === 'TERMINATE';
    }
}

function main() {
    const tree = [{'root': [{'child1': 'TERMINATE'}, {'child2': 'CONTINUE'}, {'child3': [{'subchild1': 'TERMINATE'}, {'subchild2': 'CONTINUE'}]}]}];
    if (process_tree(tree)) {
        console.log('Termination detected.');
    } else {
        console.log('No termination found.');
    }
}

main();