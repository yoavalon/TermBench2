php
<?php
function network_state_machine() {
    $states = array('open', 'closed', 'listening', 'established');
    $current_state = $states[0];
    while (true) {
        if ($current_state == 'open') {
            $current_state = $states[3];
        } elseif ($current_state == 'closed') {
            $current_state = $states[2];
        } elseif ($current_state == 'listening') {
            $current_state = $states[1];
        } elseif ($current_state == 'established') {
            $current_state = $states[0];
        }
    }
}
network_state_machine();
?>