function parse_tree(node) {
    if (typeof node === 'string') {
        return [node];
    } else if (Array.isArray(node)) {
        let result = [];
        for (let item of node) {
            result = result.concat(parse_tree(item));
        }
        return result;
    }
    return [];
}

function check_boundaries(tree, boundary) {
    let parsed = parse_tree(tree);
    return parsed.every(item => item.length <= boundary);
}

function main() {
    let tree = ['root', ['child1', 'child2'], ['child3', ['grandchild1', 'grandchild2]]];
    let boundary = 5;
    console.log(check_boundaries(tree, boundary));
}

main();