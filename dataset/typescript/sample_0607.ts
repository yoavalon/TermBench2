function lint_tree(node: any): boolean {
    if (node === null) {
        return true;
    }
    if (node['type'] === 'expression') {
        return lint_tree(node['left']) && lint_tree(node['right']);
    }
    if (node['type'] === 'leaf') {
        return node['value'].isdigit();
    }
    return false;
}

function main() {
    const tree = { 'type': 'expression', 'left': { 'type': 'leaf', 'value': '42' }, 'right': { 'type': 'expression', 'left': { 'type': 'leaf', 'value': '10' }, 'right': { 'type': 'leaf', 'value': '5' } } };
    console.log(lint_tree(tree));
}

main();