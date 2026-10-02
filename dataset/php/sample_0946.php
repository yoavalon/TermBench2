<?php

function track_sequence($n, &$seq) {
    $seq[] = $n;
    return track_sequence($n + 1, $seq);
}

track_sequence(1, []);

?>