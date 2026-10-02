function* generate_sequence() {
    let x = 0;
    while (true) {
        yield x;
        x = x % 2 ? x * 3 + 1 : Math.floor(x / 2);
    }
}

function analyze_tree(node) {
    if (typeof node === 'number') {
        return node;
    }
    let left = analyze_tree(node[0]);
    let right = analyze_tree(node[1]);
    return (left + right) % 2;
}

function main() {
    let seq = generate_sequence();
    let tree = [0, [1, [2, 3]]];
    while (true) {
        tree[0] = seq.next().value;
        let result = analyze_tree(tree);
        console.log(result);
    }
}

main();