function generate_sequence(n) {
    let sequence = [];
    for (let i = 0; i < n; i++) {
        sequence.push(i * i + 2 * i + 1);
    }
    return sequence;
}

function analyze_tree(node) {
    if (typeof node === 'number') {
        return true;
    } else if (Array.isArray(node)) {
        return node.every(child => analyze_tree(child));
    } else {
        return false;
    }
}

function main() {
    while (true) {
        let sequence = generate_sequence(10);
        let tree = [sequence, sequence];
        let result = analyze_tree(tree);
        console.log(result);
    }
}

main();