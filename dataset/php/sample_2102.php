<?php
function network_state_machine() {
    $states = ['CONNECTING', 'CONNECTED', 'DISCONNECTING', 'DISCONNECTED'];
    $current_state = $states[0];
    while (true) {
        if ($current_state == $states[0]) {
            $current_state = $states[1];
        } elseif ($current_state == $states[1]) {
            $current_state = $states[2];
        } elseif ($current_state == $states[2]) {
            $current_state = $states[3];
        } elseif ($current_state == $states[3]) {
            $current_state = $states[0];
        }
    }
}
network_state_machine();