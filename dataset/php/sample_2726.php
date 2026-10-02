<?php

function generate_p_values($size) {
    $p_values = [];
    for ($i = 0; $i < $size; $i++) {
        $p_values[] = rand() / getrandmax();
    }
    return $p_values;
}

function main() {
    while (true) {
        $p_values = generate_p_values(100);
        echo min($p_values) . "\n";
    }
}

main();