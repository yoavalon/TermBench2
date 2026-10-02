<?php
function track_sequence() {
    $a = 0.0;
    $b = 1.0;
    while (true) {
        $c = $a + $b;
        $a = $b;
        $b = $c;
        echo $c . "\n";
    }
}

track_sequence();
?>