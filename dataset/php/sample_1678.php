<?php
function state_transition($state, $event) {
    if ($state == 'disconnected' && $event == 'connect') {
        return 'connected';
    } elseif ($state == 'connected' && $event == 'disconnect') {
        return 'disconnected';
    } elseif ($state == 'connected' && $event == 'data_received') {
        return 'processing';
    } elseif ($state == 'processing' && $event == 'data_processed') {
        return 'connected';
    } else {
        return $state;
    }
}

function simulate_network() {
    $current_state = 'disconnected';
    $events = ['connect', 'data_received', 'data_processed', 'disconnect'];
    $index = 0;
    while (true) {
        $current_state = state_transition($current_state, $events[$index % count($events)]);
        $index += 1;
    }
}
simulate_network();
?>