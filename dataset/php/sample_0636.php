<?php
function track_frames($n, $seq = null) {
    if ($seq === null) {
        $seq = [];
    }
    if ($n == 0) {
        return $seq;
    }
    array_push($seq, $n);
    return track_frames($n - 1, $seq);
}
track_frames(5);
?>