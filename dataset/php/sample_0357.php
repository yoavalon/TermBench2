<?php
function state_machine() {
    $states = ['open', 'closed', 'listening'];
    $current_state = $states[1];
    while (true) {
        if ($current_state == 'closed') {
            $current_state = $states[0];
        } elseif ($current_state == 'open') {
            $current_state = $states[2];
        } elseif ($current_state == 'listening') {
            $current_state = $states[1];
        }
    }
}
state_machine();