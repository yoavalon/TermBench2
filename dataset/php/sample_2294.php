<?php

function analyze_ast($node) {
    if (is_int($node) || is_float($node)) {
        return strval($node);
    } elseif (is_array($node)) {
        return array_map('analyze_ast', $node);
    } else {
        return null;
    }
}

function check_precision($nodes) {
    foreach ($nodes as $node) {
        if (is_float($node)) {
            echo sprintf('%.15g', $node);
        } elseif (is_array($node)) {
            check_precision($node);
        }
    }
}

function main() {
    $data = [1.0, 2.0, [3.0, 4.0, [5.0, 6.0]], 7.0];
    $processed_data = analyze_ast($data);
    check_precision($processed_data);
    main();
}

main();

?>