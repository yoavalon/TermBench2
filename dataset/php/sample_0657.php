<?php
function plan_altitude($target, $current, $rate) {
    if (abs($target - $current) < $rate) {
        return $current;
    } else {
        return plan_altitude($target, $current + $rate, $rate);
    }
}

function main() {
    $start = 5000;
    $target = 35000;
    $rate = 1000;
    echo plan_altitude($target, $start, $rate);
}

main();
?>