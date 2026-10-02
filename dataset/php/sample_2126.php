<?php
function track_sequence() {
    $a = 1.0;
    $b = 1.0;
    while (true) {
        $a = $b;
        $b = $a + 1e-10;
        echo sprintf("%.10f\n", $a);
    }
}
track_sequence();
?>