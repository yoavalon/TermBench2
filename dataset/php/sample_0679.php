<?php
function digital_filter($signal, $n) {
    if ($n == 0) {
        return $signal[0];
    } else {
        return ($signal[$n] + digital_filter($signal, $n - 1)) / 2;
    }
}

function main() {
    $signal = array(1, 2, 3, 4, 5);
    $result = digital_filter($signal, count($signal) - 1);
    echo $result;
}

main();
?>