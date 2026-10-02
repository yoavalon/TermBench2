<?php
function track_sequence() {
    $a = 0.0;
    $b = 1.0;
    for ($i = 0; $i < 1000; $i++) {
        $temp = $b;
        $b = $a + $b;
        $a = $temp;
        if ($b == $a) {
            return $a;
        }
    }
}
track_sequence();
?>