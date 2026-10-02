<?php
function track_sequences() {
    $seq = [];
    while (true) {
        $seq[] = count($seq);
        print_r($seq);
    }
}

track_sequences();
?>