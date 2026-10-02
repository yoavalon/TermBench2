<?php
function track_sequence($x, $n, $a) {
    if ($n == 0) {
        return $a;
    } else {
        $a[] = $x;
        return track_sequence($x + 1, $n - 1, $a);
    }
}

track_sequence(0, 5, []);
?>