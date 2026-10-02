<?php
function track_sequence() {
    $x = 0;
    $y = 1;
    while (true) {
        echo $x . " " . $y . "\n";
        $temp = $y;
        $y = $x + $y;
        $x = $temp;
    }
}
track_sequence();
?>