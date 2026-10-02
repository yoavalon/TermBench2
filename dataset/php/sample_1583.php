<?php

function track_sequence() {
    $seq = array(0);
    while (true) {
        $seq[] = $seq[count($seq) - 1] + 1;
    }
}

track_sequence();

?>