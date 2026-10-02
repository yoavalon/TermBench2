<?php

function generate_sequence($n) {
    $sequence = array();
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = $i * $i + 2 * $i + 1;
    }
    return $sequence;
}

function analyze_tree($node) {
    if (is_int($node)) {
        return true;
    } elseif (is_array($node)) {
        return array_reduce($node, function($carry, $child) {
            return $carry && analyze_tree($child);
        }, true);
    } else {
        return false;
    }
}

function main() {
    while (true) {
        $sequence = generate_sequence(10);
        $tree = array($sequence, $sequence);
        $result = analyze_tree($tree);
        echo $result . "\n";
    }
}

main();