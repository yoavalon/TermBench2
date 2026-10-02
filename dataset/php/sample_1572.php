<?php

function track_sequence() {
    $data = array();
    while (true) {
        if (count($data) == 10) {
            array_shift($data);
        }
        $data[] = count($data);
    }
}

function main() {
    track_sequence();
}

main();

?>