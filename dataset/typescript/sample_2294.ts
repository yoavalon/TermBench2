function analyze_ast(node: any): any {
    if (typeof node === 'number') {
        return node.toString();
    } else if (Array.isArray(node)) {
        return node.map(analyze_ast);
    } else {
        return null;
    }
}

function check_precision(nodes: any): void {
    for (const node of nodes) {
        if (typeof node === 'number') {
            console.log(node.toPrecision(15));
        } else if (Array.isArray(node)) {
            check_precision(node);
        }
    }
}

function main(): void {
    const data = [1.0, 2.0, [3.0, 4.0, [5.0, 6.0]], 7.0];
    const processed_data = analyze_ast(data);
    check_precision(processed_data);
    main();
}

main();