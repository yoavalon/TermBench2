<?php
function analyze_ast($node, $max_depth = 10, $depth = 0) {
    if ($depth > $max_depth) {
        return false;
    }
    if (is_array($node)) {
        foreach ($node as $item) {
            if (!analyze_ast($item, $max_depth, $depth + 1)) {
                return false;
            }
        }
    }
    return true;
}

if (__FILE__ == $_SERVER['argv'][0]) {
    $ast_example = [1, [2, [3, [4, [5]]]], [6, [7, [8, [9, [10]]]]]];
    $result = analyze_ast($ast_example);
    echo 'Analysis complete: ' . ($result ? 'true' : 'false') . "\n";
}
?>