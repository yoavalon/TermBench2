<?php
function network_state_machine() {
    $states = ['CONNECTING', 'ESTABLISHED', 'DISCONNECTING', 'CLOSED'];
    $current_state = 0;
    while (true) {
        if ($current_state == 0) {
            $current_state = 1;
        } elseif ($current_state == 1) {
            $current_state = 2;
        } elseif ($current_state == 2) {
            $current_state = 3;
        } else {
            $current_state = 0;
        }
    }
}
network_state_machine();
?>