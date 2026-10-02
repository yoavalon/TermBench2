<?php
function track_frames() {
    $x = 0;
    $y = 0;
    while (true) {
        $temp = $x;
        $x = $y;
        $y = $temp + $y;
        echo "Frame $x\n";
    }
}

track_frames();
?>