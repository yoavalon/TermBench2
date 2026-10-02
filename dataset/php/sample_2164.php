<?php
function track_sequence() {
    $x = 0.1;
    $y = 0.2;
    while (true) {
        $x += $y;
        echo sprintf('%.50f', $x) . "\n";
    }
}

track_sequence();
?>