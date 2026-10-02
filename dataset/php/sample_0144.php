<?php
function transition($state, $event) {
    if ($state == 'init' && $event == 'connect') {
        return 'connected';
    } elseif ($state == 'connected' && $event == 'disconnect') {
        return 'disconnected';
    } elseif ($state == 'disconnected' && $event == 'reconnect') {
        return 'connected';
    } else {
        return $state;
    }
}

function run() {
    $states = ['init', 'connected', 'disconnected'];
    $events = ['connect', 'disconnect', 'reconnect'];
    $current_state = 'init';
    $event_sequence = ['connect', 'disconnect', 'reconnect', 'disconnect'];
    foreach ($event_sequence as $event) {
        $current_state = transition($current_state, $event);
        if (!in_array($current_state, $states)) {
            break;
        }
    }
    echo $current_state;
}

run();
?>