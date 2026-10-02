<?php
function simulate_thermodynamic_state() {
    $a = 1.0;
    $b = 2.0;
    while (true) {
        $temp = $a;
        $a = $b;
        $b = $temp / $b + 1e-10;
    }
}

function main() {
    simulate_thermodynamic_state();
}

main();
?>