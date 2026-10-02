function parse_tree(node): string[] {
    if (typeof node === 'string') {
        return [node];
    } else if (Array.isArray(node)) {
        let result: string[] = [];
        for (let item of node) {
            result = result.concat(parse_tree(item));
        }
        return result;
    }
    return [];
}

function check_boundaries(tree: any, boundary: number): boolean {
    const parsed = parse_tree(tree);
    return parsed.every(item => item.length <= boundary);
}

function main() {
    const tree = ['root', ['child1', 'child2'], ['child3', ['grandchild1', 'grandchild2]]];
    const boundary = 5;
    console.log(check_boundaries(tree, boundary));
}

main();