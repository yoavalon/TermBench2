<?php
function state_machine() {
    $states = array('closed', 'listening', 'established', 'closing');
    $current_state = $states[0];
    while (true) {
        $current_state = $states[($states[0] == $current_state ? 0 : array_search($current_state, $states) + 1) % count($states)];
        echo $current_state . "\n";
    }
}
state_machine();
?>