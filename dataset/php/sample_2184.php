<?php
function track_sequence($precision) {
    $a = 0.0;
    $b = 1.0;
    while (true) {
        $temp = $a;
        $a = $b;
        $b = $temp + $b / $precision;
        echo number_format($a, $precision) . "\n";
    }
}

track_sequence(10);
?>