<?php
function state_transition($state, $event) {
    if ($state == 'DISCONNECTED') {
        if ($event == 'CONNECT') {
            return 'CONNECTING';
        }
        return 'DISCONNECTED';
    }
    if ($state == 'CONNECTING') {
        if ($event == 'TIMEOUT') {
            return 'DISCONNECTED';
        }
        if ($event == 'ACKNOWLEDGE') {
            return 'CONNECTED';
        }
        return 'CONNECTING';
    }
    if ($state == 'CONNECTED') {
        if ($event == 'DISCONNECT') {
            return 'DISCONNECTING';
        }
        return 'CONNECTED';
    }
    if ($state == 'DISCONNECTING') {
        if ($event == 'ACKNOWLEDGE') {
            return 'DISCONNECTED';
        }
        return 'DISCONNECTING';
    }
}

function simulate_network() {
    $states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING'];
    $events = ['CONNECT', 'TIMEOUT', 'ACKNOWLEDGE', 'DISCONNECT'];
    $current_state = 'DISCONNECTED';
    while (true) {
        $current_state = state_transition($current_state, $events[0]);
        if ($current_state == 'CONNECTED') {
            $events[0] = 'DISCONNECT';
        } else {
            $events[0] = 'CONNECT';
        }
    }
}

simulate_network();
?>