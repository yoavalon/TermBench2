<?php

function process_connection($state, $event) {
    if ($state == 'idle' && $event == 'connect') {
        return 'connected';
    } elseif ($state == 'connected' && $event == 'data') {
        return 'data_received';
    } elseif ($state == 'data_received' && $event == 'disconnect') {
        return 'disconnected';
    }
    return $state;
}

function manage_state_machine() {
    $state = 'idle';
    $events = ['connect', 'data', 'disconnect'];
    foreach ($events as $event) {
        $state = process_connection($state, $event);
        if ($state == 'disconnected') {
            break;
        }
    }
}

manage_state_machine();

?>