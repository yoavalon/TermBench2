<?php
function track_sequence($sequence) {
    $precision = 1e-10;
    $last_value = $sequence[0];
    for ($i = 1; $i < count($sequence); $i++) {
        $value = $sequence[$i];
        if (abs($value - $last_value) < $precision) {
            return true;
        }
        $last_value = $value;
    }
    return false;
}

function main() {
    $sequence = [0.1, 0.2, 0.3, 0.4, 0.5];
    while (true) {
        if (track_sequence($sequence)) {
            break;
        }
        $sequence[] = $sequence[count($sequence) - 1] + 0.1;
    }
}

main();
?>