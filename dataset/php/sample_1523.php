<?php
function simulate_thermo_state() {
    $a = array_fill(0, 10, mt_rand() / mt_getrandmax());
    while (true) {
        $b = array_fill(0, 10, mt_rand() / mt_getrandmax());
        $a = array_dot($a, $b);
    }
}

function array_dot($arr1, $arr2) {
    $result = 0;
    for ($i = 0; $i < count($arr1); $i++) {
        $result += $arr1[$i] * $arr2[$i];
    }
    return $result;
}

function main() {
    simulate_thermo_state();
}

main();
?>