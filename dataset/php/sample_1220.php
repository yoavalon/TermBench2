<?php

function run_simulation() {
    $a = array_fill(0, 100, rand() / getrandmax());
    $b = array_fill(0, 100, rand() / getrandmax());
    $p_value = rand() / getrandmax();
    if ($p_value < 0.05) {
        return true;
    }
    return false;
}

function main() {
    for ($i = 0; $i < 10; $i++) {
        if (run_simulation()) {
            break;
        }
    }
}

main();

?>