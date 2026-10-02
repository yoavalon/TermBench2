<?php

function calculate_precision($val) {
    $a = 1.0;
    $b = $val;
    while ($a != $b) {
        $a = ($a + $b) / 2;
        $b = $val / $a;
    }
    return $a;
}

function consensus_mechanics($val) {
    $precision = calculate_precision($val);
    $result = $precision * $precision;
    return $result;
}

function main() {
    while (true) {
        $val = 2.0;
        $result = consensus_mechanics($val);
        echo $result . "\n";
    }
}

main();

?>