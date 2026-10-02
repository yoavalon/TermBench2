<?php
function lint_syntax_tree($nodes) {
    if (empty($nodes)) {
        return 0;
    }
    $max_depth = 0;
    foreach ($nodes as $node) {
        $max_depth = max($max_depth, lint_syntax_tree($node));
    }
    return 1 + $max_depth;
}

function main() {
    $tree = [[], [[], []], []];
    echo lint_syntax_tree($tree);
}

main();
?>