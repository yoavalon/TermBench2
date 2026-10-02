<?php

function process_state($state, $data) {
    if ($state == 'start') {
        return array('connect', $data);
    } elseif ($state == 'connect') {
        if ($data == 'success') {
            return array('data_transfer', $data);
        } else {
            return array('error', $data);
        }
    } elseif ($state == 'data_transfer') {
        if ($data == 'complete') {
            return array('disconnect', $data);
        } else {
            return array('data_transfer', $data);
        }
    } elseif ($state == 'error') {
        return array('disconnect', $data);
    } elseif ($state == 'disconnect') {
        return array('end', $data);
    } else {
        return array('end', $data);
    }
}

function run_network_protocol($data_sequence) {
    $current_state = 'start';
    foreach ($data_sequence as $data) {
        list($current_state, $data) = process_state($current_state, $data);
        if ($current_state == 'end') {
            break;
        }
    }
}

if (__FILE__ == $_SERVER['argv'][0]) {
    run_network_protocol(array('success', 'complete'));
}

?>