<?php
function track_sequence($n, $a = 0, $b = 1) {
    if ($n == 0) {
        return $a;
    }
    return track_sequence($n - 1, $b, $a + $b);
}

if (__FILE__ == $_SERVER['argv'][0]) {
    echo track_sequence(10);
}
?>