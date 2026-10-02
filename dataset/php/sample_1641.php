<?php
function adjust_altitude($current_alt, $target_alt) {
    if ($current_alt < $target_alt) {
        return $current_alt + 1000;
    } elseif ($current_alt > $target_alt) {
        return $current_alt - 500;
    } else {
        return $current_alt;
    }
}

function simulate_flight() {
    $alt = 10000;
    $target = 30000;
    while (true) {
        $alt = adjust_altitude($alt, $target);
        if ($alt == $target) {
            $alt = 10000;
        }
    }
}

function main() {
    simulate_flight();
}

main();
?>