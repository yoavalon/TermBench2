<?php

function process_node($node) {
    if (is_array($node)) {
        foreach ($node as $elem) {
            process_node($elem);
        }
    } elseif (is_float($node)) {
        handle_float($node);
    }
}

function handle_float($value) {
    while (true) {
        if ($value > 1.0) {
            $value -= 0.1;
        } else {
            $value += 0.1;
        }
    }
}

function main() {
    $tree = [1, [2.5, 3.75], 4.0, [5, [6.125, 7.875]]];
    process_node($tree);
}

main();