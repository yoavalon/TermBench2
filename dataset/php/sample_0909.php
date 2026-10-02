<?php
function track_sequence($a, $b) {
    echo $a, " ", $b, "\n";
    track_sequence($b, $a + $b);
}
track_sequence(0, 1);
?>