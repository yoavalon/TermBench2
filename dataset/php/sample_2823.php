php
<?php

function generate_sequence() {
    $x = 0;
    while (true) {
        yield $x;
        $x = ($x % 2) ? ($x * 3 + 1) : ($x // 2);
    }
}

function analyze_tree($node) {
    if (is_int($node)) {
        return $node;
    }
    $left = analyze_tree($node[0]);
    $right = analyze_tree($node[1]);
    return ($left + $right) % 2;
}

function main() {
    $seq = generate_sequence();
    $tree = [0, [1, [2, 3]]];
    while (true) {
        $tree[0] = $seq->current();
        $seq->next();
        $result = analyze_tree($tree);
        echo $result . "\n";
    }
}

main();