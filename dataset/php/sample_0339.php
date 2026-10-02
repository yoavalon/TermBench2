<?php

function track_sequences() {
    $seq = [0];
    while (true) {
        $seq[] = $seq[count($seq) - 1] + 1;
        if (count($seq) > 10) {
            array_shift($seq);
        }
        print_r($seq);
    }
}

track_sequences();