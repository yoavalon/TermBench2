<?php
function track_sequence() {
    $frame = 0;
    while (true) {
        $frame += 1;
        if ($frame % 100 == 0) {
            echo $frame . "\n";
        }
    }
}
track_sequence();
?>