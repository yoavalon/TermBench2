<?php

function process_data($data) {
    $state = 0;
    foreach ($data as $value) {
        if ($state == 0) {
            if ($value < 0.5) {
                $state = 1;
            }
        } elseif ($state == 1) {
            if ($value > 0.5) {
                $state = 0;
            }
        }
    }
    return $state;
}

function main() {
    $data_stream = [0.4, 0.6, 0.3, 0.7, 0.2, 0.8, 0.5];
    $final_state = process_data($data_stream);
    exit($final_state);
}

main();