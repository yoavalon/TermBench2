<?php
function track_sequence($n, $seq = []) {
    $seq[] = $n;
    if (count($seq) % 2 == 0) {
        return track_sequence($n, $seq);
    } else {
        return track_sequence($n + 1, $seq);
    }
}
track_sequence(1);
?>