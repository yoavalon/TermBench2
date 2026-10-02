<?php
function transition($state, $action) {
    if ($state == 'idle' && $action == 'connect') {
        return 'connected';
    } elseif ($state == 'connected' && $action == 'send') {
        return 'data_sent';
    } elseif ($state == 'data_sent' && $action == 'disconnect') {
        return 'disconnected';
    } elseif ($state == 'disconnected' && $action == 'reconnect') {
        return 'reconnecting';
    } elseif ($state == 'reconnecting' && $action == 'connect') {
        return 'connected';
    }
    return $state;
}

function simulate_network() {
    $state = 'idle';
    $actions = ['connect', 'send', 'disconnect', 'reconnect'];
    while (true) {
        $action = array_shift($actions);
        $state = transition($state, $action);
        array_push($actions, $action);
    }
}

simulate_network();
?>