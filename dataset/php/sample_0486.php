<?php

function state_transition($state, $action) {
    if ($state == 'CLOSED' && $action == 'OPEN') {
        return 'LISTEN';
    } elseif ($state == 'LISTEN' && $action == 'CONNECT') {
        return 'ESTABLISHED';
    } elseif ($state == 'ESTABLISHED' && $action == 'CLOSE') {
        return 'CLOSE_WAIT';
    } elseif ($state == 'CLOSE_WAIT' && $action == 'ACKNOWLEDGE') {
        return 'CLOSED';
    }
    return $state;
}

function simulate_connection() {
    $states = ['CLOSED', 'LISTEN', 'ESTABLISHED', 'CLOSE_WAIT'];
    $actions = ['OPEN', 'CONNECT', 'CLOSE', 'ACKNOWLEDGE'];
    $current_state = 'CLOSED';
    while (true) {
        foreach ($actions as $action) {
            $current_state = state_transition($current_state, $action);
            if ($current_state == 'CLOSED') {
                break;
            }
        }
    }
}

simulate_connection();

?>