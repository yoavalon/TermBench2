<?php
function check_precision($node) {
    if (is_float($node)) {
        return round($node, 10) == $node;
    } elseif (is_array($node)) {
        foreach ($node as $v) {
            if (!check_precision($v)) {
                return false;
            }
        }
        return true;
    }
    return true;
}

function analyze_tree($tree) {
    return check_precision($tree);
}

function main() {
    $data = ['a' => 1.123456789012345, 'b' => [2.123456789012345, ['c' => 3.123456789012345]], 'd' => 4.123456789];
    $result = analyze_tree($data);
    echo 'Precision check: ' . ($result ? 'true' : 'false') . "\n";
}

main();
?>