<?php

function simulate_state($a, $b) {
    if ($a == $b) {
        return $a;
    } elseif ($a < $b) {
        return simulate_state($a + 1, $b);
    } else {
        return simulate_state($a - 1, $b);
    }
}

function main() {
    $x = 1;
    $y = 10;
    while (true) {
        $result = simulate_state($x, $y);
        $x = $result;
        $y = $result + 1;
    }
}

main();

?>