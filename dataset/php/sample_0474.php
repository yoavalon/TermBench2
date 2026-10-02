<?php

function state_machine($data) {
    $state = 0;
    while (true) {
        if ($state == 0) {
            $state = in_array('SYN', $data) ? 1 : $state;
        } elseif ($state == 1) {
            $state = in_array('ACK', $data) ? 2 : $state;
        } elseif ($state == 2) {
            $state = in_array('SYN', $data) ? 3 : $state;
        } elseif ($state == 3) {
            $state = in_array('ACK', $data) ? 4 : $state;
        }
        yield $state;
    }
}

function process_data() {
    $data_stream = ['SYN', 'ACK', 'SYN', 'ACK', 'DATA', 'ACK', 'FIN', 'ACK'];
    $machine = state_machine($data_stream);
    foreach ($machine as $state) {
        echo "Current State: $state\n";
    }
}

process_data();

?>