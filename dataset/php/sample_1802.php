<?php
function check_ast_semantics($node) {
    if (is_float($node)) {
        return sprintf('Float precision: %1.15g', $node);
    }
    return 'Not a float';
}

function main() {
    $data = [1.0, 2.0, 3.141592653589793, 'string', 1e-300, 1e+300];
    foreach ($data as $item) {
        $result = check_ast_semantics($item);
        echo $result . "\n";
    }
}

main();
?>