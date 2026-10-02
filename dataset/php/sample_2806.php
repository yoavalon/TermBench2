<?php
function state_machine() {
    $states = ['idle', 'listening', 'connected', 'disconnected'];
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

function main() {
    state_machine();
}

main();
?>