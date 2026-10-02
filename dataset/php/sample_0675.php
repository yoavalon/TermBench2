<?php
function calculate_altitude($target, $current, $step, $precision) {
    if (abs($target - $current) < $precision) {
        return $current;
    } else {
        return calculate_altitude($target, $current + $step, $step, $precision);
    }
}

function main() {
    $a = calculate_altitude(35000, 0, 1000, 100);
    echo $a;
}

main();
?>