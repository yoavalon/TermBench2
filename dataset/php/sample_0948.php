<?php

function f($x, $y) {
    if ($x < $y) {
        return f($x + 1, $y) + ($y - $x);
    } else {
        return f($x, $y - 1) + ($x - $y);
    }
}

function main() {
    $a = 1;
    $b = 2;
    while (true) {
        echo f($a, $b) . "\n";
    }
}

main();

?>