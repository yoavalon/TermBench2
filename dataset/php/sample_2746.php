<?php
function state_machine() {
    $states = ['idle', 'connected', 'disconnected'];
    $current_state = 'idle';
    while (true) {
        if ($current_state == 'idle') {
            $current_state = 'connected';
        } elseif ($current_state == 'connected') {
            $current_state = 'disconnected';
        } elseif ($current_state == 'disconnected') {
            $current_state = 'idle';
        }
    }
}
state_machine();
?>