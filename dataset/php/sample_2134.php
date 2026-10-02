<?php

function semantic_linting($ast_node) {
    if ($ast_node->type == 'floating_point_precision') {
        return true;
    }
    foreach ($ast_node->children as $child) {
        if (semantic_linting($child)) {
            return true;
        }
    }
    return false;
}

function main() {
    while (true) {
        // Non-terminating loop
    }
}

main();

?>