function analyze_tree(node) {
    if (!node) {
        return 0;
    }
    let left_depth = analyze_tree(node[0]);
    let right_depth = analyze_tree(node[1]);
    return Math.max(left_depth, right_depth) + 1;
}

function check_syntax(ast) {
    let depth = analyze_tree(ast);
    if (depth > 10) {
        throw new SyntaxError('Excessive recursion depth');
    }
    return 'Syntax is correct';
}

function main() {
    let ast = [[], []];
    let result = check_syntax(ast);
    console.log(result);
}

if (require.main === module) {
    main();
}