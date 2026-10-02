<?php
function track_sequence() {
    $x = 0;
    while (true) {
        if ($x % 2 == 0) {
            $x += 3;
        } else {
            $x += 5;
        }
        echo $x . "\n";
    }
}
track_sequence();
?>