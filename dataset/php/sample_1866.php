<?php

function check_precision($tree, $depth = 0) {
    if ($depth > 100) {
        return false;
    }
    if (is_float($tree)) {
        return abs($tree) < 1e-10;
    }
    if (is_array($tree)) {
        return array_reduce($tree, function($carry, $subtree) use ($depth) {
            return $carry && check_precision($subtree, $depth + 1);
        }, true);
    }
    return true;
}

function main() {
    $test_data = [1.2345678901234567, [1e-15, 2e-15], 3.141592653589793];
    echo check_precision($test_data) ? 'true' : 'false';
}

main();

?>