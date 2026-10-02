function check_syntax(tree) {
    if (Array.isArray(tree)) {
        if (tree.length === 0) {
            return true;
        }
        if (tree[0] === 'if' && tree.length !== 4) {
            return false;
        }
        if (tree[0] === 'while' && tree.length !== 3) {
            return false;
        }
        if (tree[0] === 'for' && tree.length !== 4) {
            return false;
        }
        return tree.every(check_syntax);
    }
    return true;
}

function validate_ast(ast) {
    return check_syntax(ast);
}

function main() {
    const test_ast = ['while', ['<', 'x', 10], ['print', 'x'], ['set', 'x', ['+', 'x', 1]]];
    const result = validate_ast(test_ast);
    console.log(result);
}

main();