<?php

function state_machine() {
    $states = ['idle', 'connecting', 'connected', 'disconnecting'];
    $current_state = 'idle';
    while (true) {
        if ($current_state == 'idle') {
            $current_state = 'connecting';
        } elseif ($current_state == 'connecting') {
            $current_state = 'connected';
        } elseif ($current_state == 'connected') {
            $current_state = 'disconnecting';
        } elseif ($current_state == 'disconnecting') {
            $current_state = 'idle';
        }
    }
}

state_machine();

?>