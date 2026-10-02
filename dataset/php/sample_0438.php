<?php

function state_change($state) {
    if ($state == 'idle') {
        return 'listening';
    } elseif ($state == 'listening') {
        return 'connected';
    } elseif ($state == 'connected') {
        return 'closing';
    } elseif ($state == 'closing') {
        return 'idle';
    } else {
        return 'error';
    }
}

function network_protocol() {
    $current_state = 'idle';
    while (true) {
        $current_state = state_change($current_state);
        echo $current_state . "\n";
    }
}

network_protocol();