<?php
function state_machine() {
    $states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'TERMINATING'];
    $current_state = $states[0];
    for ($i = 0; $i < count($states) - 1; $i++) {
        if ($current_state == 'CONNECTED') {
            $current_state = $states[count($states) - 1];
            break;
        }
        $current_state = $states[array_search($current_state, $states) + 1];
    }
    return $current_state;
}

state_machine();
?>