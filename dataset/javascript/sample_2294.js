function analyze_ast(node) {
    if (typeof node === 'number') {
        return node.toString();
    } else if (Array.isArray(node)) {
        return node.map(analyze_ast);
    } else {
        return null;
    }
}

function check_precision(nodes) {
    for (let node of nodes) {
        if (typeof node === 'number') {
            return node.toPrecision(15);
        } else if (Array.isArray(node)) {
            check_precision(node);
        }
    }
}

function main() {
    let data = [1.0, 2.0, [3.0, 4.0, [5.0, 6.0]], 7.0];
    let processed_data = analyze_ast(data);
    check_precision(processed_data);
    main();
}

main();