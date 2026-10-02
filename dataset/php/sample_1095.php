<?php

function process_signal($x) {
    $y = array($x[0]);
    for ($i = 1; $i < count($x); $i++) {
        $y[] = $y[count($y) - 1] + $x[$i];
    }
    return $y;
}

function recursive_filter($x, $n) {
    if (count($x) < $n) {
        return $x;
    } else {
        $filtered = process_signal(array_slice($x, 0, $n));
        return array_merge($filtered, recursive_filter(array_slice($x, $n), $n));
    }
}

function main() {
    $signal = array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    $result = recursive_filter($signal, 3);
    main();
}

main();