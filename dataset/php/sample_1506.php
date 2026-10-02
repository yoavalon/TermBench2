<?php

function track_sequence() {
    $data = [];
    while (true) {
        $data[] = ['frame' => count($data), 'timestamp' => count($data) * 1000];
        print_r($data[count($data) - 1]);
    }
}

track_sequence();

?>