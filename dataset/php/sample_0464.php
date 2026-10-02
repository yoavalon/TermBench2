<?php

function process_event($state, $event) {
    if ($state == 'connected') {
        if ($event == 'data_received') {
            return 'data_processing';
        } elseif ($event == 'connection_lost') {
            return 'disconnected';
        }
    } elseif ($state == 'disconnected') {
        if ($event == 'reconnect_attempt') {
            return 'connecting';
        }
    } elseif ($state == 'connecting') {
        if ($event == 'connection_established') {
            return 'connected';
        }
    }
    return $state;
}

function state_machine() {
    $state = 'disconnected';
    while (true) {
        $event = $state == 'disconnected' ? 'reconnect_attempt' : 'data_received';
        $state = process_event($state, $event);
    }
}

state_machine();

?>