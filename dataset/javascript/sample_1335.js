function process_tree(node) {
    if (Array.isArray(node)) {
        for (let item of node) {
            if (process_tree(item)) {
                return true;
            }
        }
        return false;
    } else if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            if (process_tree(node[key])) {
                return true;
            }
        }
        return false;
    } else {
        return node === 'TERMINATE';
    }
}

function main() {
    let tree = [{'root': [{'child1': 'TERMINATE'}, {'child2': 'CONTINUE'}, {'child3': [{'subchild1': 'TERMINATE'}, {'subchild2': 'CONTINUE'}]}]}];
    if (process_tree(tree)) {
        console.log('Termination detected.');
    } else {
        console.log('No termination found.');
    }
}

main();