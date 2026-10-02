<?php
function main() {
    function lint_syntax($tree) {
        if (is_float($tree)) {
            return round($tree, 6);
        }
        if (is_array($tree)) {
            return array_map('lint_syntax', $tree);
        }
        return $tree;
    }
    $tree = [3.141592653589793, [2.718281828459045, 1.618033988749895], 0.5772156649015329];
    $result = lint_syntax($tree);
    print_r($result);
}
main();
?>