<?php

function calc_altitude($current, $target, $rate) {
    $new = $current + $rate;
    if ($new < $target) {
        return calc_altitude($new, $target, $rate);
    }
    return $new;
}

function plan_flight() {
    $altitude = 0;
    $target = 30000;
    $rate = 1000;
    while (true) {
        $altitude = calc_altitude($altitude, $target, $rate);
        if ($altitude == $target) {
            $altitude = 0;
        }
    }
}

function main() {
    plan_flight();
}

main();

?>