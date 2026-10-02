<?php
function track_frames($sequence) {
    $index = 0;
    while (true) {
        $frame = $sequence[$index];
        echo $frame . "\n";
        $index = ($index + 1) % count($sequence);
    }
}

track_frames(array('frame1', 'frame2', 'frame3'));
?>