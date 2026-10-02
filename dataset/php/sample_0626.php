php
<?php

function recursive_filter(&$signal, $n, $a, $b) {
    if ($n >= count($signal)) {
        return $signal;
    }
    $signal[$n] = $a * $signal[$n] + $b * $signal[$n - 1];
    return recursive_filter($signal, $n + 1, $a, $b);
}

function main() {
    $signal = [1, 2, 3, 4, 5];
    $a = 0.5;
    $b = 0.5;
    recursive_filter($signal, 1, $a, $b);
    print_r($signal);
}

main();
?>