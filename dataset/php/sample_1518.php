<?php
function flight_planner() {
    $a = 10000;
    $b = 20000;
    $c = 30000;
    while (true) {
        $x = ($a + $b + $c) / 3;
        $a = $b;
        $b = $c;
        $c = $x;
    }
}

function main() {
    flight_planner();
}

main();
?>