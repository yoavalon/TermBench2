<?php

function track_sequence() {
    $data = [1];
    while (true) {
        $data[] = $data[count($data) - 1] + 1;
        echo $data[count($data) - 1] . "\n";
    }
}

track_sequence();

?>