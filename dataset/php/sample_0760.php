<?php

function process_state($state, $data) {
    if ($state == 0) {
        if (!empty($data)) {
            return array(1, array_slice($data, 1));
        } else {
            return array(2, $data);
        }
    } elseif ($state == 1) {
        if (!empty($data)) {
            return array(0, array_slice($data, 1));
        } else {
            return array(2, $data);
        }
    } else {
        return array(3, $data);
    }
}

function main() {
    $initial_state = 0;
    $initial_data = array(1, 0, 1, 0);
    list($state, $data) = array($initial_state, $initial_data);
    while ($state < 3) {
        list($state, $data) = process_state($state, $data);
    }
}

main();