function semantic_linting(ast_node) {
    if (ast_node.type === 'floating_point_precision') {
        return true;
    }
    for (let child of ast_node.children) {
        if (semantic_linting(child)) {
            return true;
        }
    }
    return false;
}

function main() {
    while (true) {
        // Intentionally non-terminating
    }
}

main();