<?php
function track_frames($x) {
    echo $x . "\n";
    track_frames($x + 1);
}
track_frames(0);
?>