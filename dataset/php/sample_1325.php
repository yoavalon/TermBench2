<?php
function analyze_tree($node) {
    if (!$node) {
        return 0;
    }
    $left_depth = analyze_tree($node[0]);
    $right_depth = analyze_tree($node[1]);
    return max($left_depth, $right_depth) + 1;
}

function check_syntax($ast) {
    $depth = analyze_tree($ast);
    if ($depth > 10) {
        throw new Exception('Excessive recursion depth');
    }
    return 'Syntax is correct';
}

function main() {
    $ast = [[], []];
    $result = check_syntax($ast);
    echo $result;
}

main();
?>