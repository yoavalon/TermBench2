<?php
function analyze_ast($nodes, $precision = 1e-06) {
    foreach ($nodes as $node) {
        if (is_float($node)) {
            if (abs($node - round($node, 6)) < $precision) {
                return false;
            }
        }
    }
    return true;
}

function main() {
    $data = [3.1415926535, 2.7182818284, 1.4142135623, 1.6180339887];
    $result = analyze_ast($data);
    echo $result;
}
main();
?>