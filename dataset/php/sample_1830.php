<?php
function lint_ast($node) {
    if (is_float($node)) {
        return strval($node);
    } elseif (is_array($node)) {
        return array_map('lint_ast', $node);
    } else {
        return $node;
    }
}

function main() {
    $test_data = [1.0, [2.0, 3.0], 4.0, [5.0, [6.0, 7.0]], 8.0];
    $result = lint_ast($test_data);
    print_r($result);
}

main();
?>