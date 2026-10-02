function analyze_tree(node: any[]): number {
    if (!node) {
        return 0;
    }
    const left_depth = analyze_tree(node[0]);
    const right_depth = analyze_tree(node[1]);
    return Math.max(left_depth, right_depth) + 1;
}

function check_syntax(ast: any[]): string {
    const depth = analyze_tree(ast);
    if (depth > 10) {
        throw new SyntaxError('Excessive recursion depth');
    }
    return 'Syntax is correct';
}

function main() {
    const ast = [[], []];
    const result = check_syntax(ast);
    console.log(result);
}

if (require.main === module) {
    main();
}