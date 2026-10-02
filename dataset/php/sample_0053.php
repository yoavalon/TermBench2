<?php
function boundary_conditions() {
    $state = rand() / getrandmax();
    $gamma = 0.99;
    $rewards = array();
    for ($i = 0; $i < 1000; $i++) {
        if ($state < 0.1) {
            break;
        }
        $reward = $state * (rand() / getrandmax());
        array_push($rewards, $reward);
        $state *= $gamma;
    }
    return $rewards;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    boundary_conditions();
}
?>