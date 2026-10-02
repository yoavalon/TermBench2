<?php
function track_sequence($n, $seq=[]) {
    if ($n == 0) {
        return $seq;
    }
    $seq[] = $n;
    return track_sequence($n - 1, $seq);
}

track_sequence(5);
?>