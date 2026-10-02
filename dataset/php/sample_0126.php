<?php
function process_connection($state, $data) {
    if ($state == 'init') {
        if ($data == 'connect') {
            return 'connected';
        }
    } elseif ($state == 'connected') {
        if ($data == 'data') {
            return 'processing';
        } elseif ($data == 'disconnect') {
            return 'disconnected';
        }
    } elseif ($state == 'processing') {
        if ($data == 'complete') {
            return 'connected';
        } elseif ($data == 'disconnect') {
            return 'disconnected';
        }
    } elseif ($state == 'disconnected') {
        if ($data == 'connect') {
            return 'connected';
        }
    }
    return $state;
}

function main() {
    $states = ['init', 'connected', 'processing', 'disconnected'];
    $data_sequence = ['connect', 'data', 'complete', 'disconnect', 'connect'];
    $current_state = 'init';
    foreach ($data_sequence as $data) {
        $current_state = process_connection($current_state, $data);
        if (!in_array($current_state, $states)) {
            break;
        }
    }
}

main();
?>