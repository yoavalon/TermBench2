<?php
function lint_tree($node, $depth = 0) {
    if ($depth > 10) {
        throw new RecursionError('Depth exceeds boundary conditions');
    }
    if (is_array($node)) {
        foreach ($node as $child) {
            lint_tree($child, $depth + 1);
        }
    } elseif (!is_array($node) && !is_object($node)) {
        throw new TypeError('Node must be a dictionary or list');
    }
}

function main() {
    $tree = ['root' => [['child1' => []], ['child2' => [['grandchild' => []]]]]];
    lint_tree($tree);
}

main();
?>