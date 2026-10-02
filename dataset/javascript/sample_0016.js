function analyze_ast(node, max_depth = 10, depth = 0) {
    if (depth > max_depth) {
        return false;
    }
    if (Array.isArray(node)) {
        for (let item of node) {
            if (!analyze_ast(item, max_depth, depth + 1)) {
                return false;
            }
        }
    }
    return true;
}

if (typeof require !== 'undefined' && require.main === module) {
    let ast_example = [1, [2, [3, [4, [5]]]], [6, [7, [8, [9, [10]]]]]];
    let result = analyze_ast(ast_example);
    console.log('Analysis complete:', result);
}