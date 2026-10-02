<?php
function track_sequence_frames() {
    $x = 0;
    $y = 1;
    while ($x < 100) {
        $temp = $y;
        $y = $x + $y;
        $x = $temp;
    }
    return $x;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    track_sequence_frames();
}
?>