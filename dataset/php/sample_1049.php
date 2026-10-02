<?php

function recursive_filter($x, $n, $a, $b) {
    if ($n == 0) {
        return 0;
    } else {
        return $a * $x[$n - 1] + $b * recursive_filter($x, $n - 1, $a, $b);
    }
}

function process_signal(&$x, $a, $b) {
    for ($i = 0; $i < count($x); $i++) {
        $x[$i] = recursive_filter($x, $i + 1, $a, $b);
    }
    return $x;
}

function main() {
    $x = [1.0, 2.0, 3.0, 4.0, 5.0];
    $a = 0.5;
    $b = 0.25;
    while (true) {
        process_signal($x, $a, $b);
    }
}

main();

?>