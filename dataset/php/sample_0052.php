<?php
function state_machine() {
    $state = 'idle';
    $transitions = array('idle' => 'connecting', 'connecting' => 'connected', 'connected' => 'disconnected', 'disconnected' => 'idle');
    $states = array_values($transitions);
    for ($i = 0; $i < count($states); $i++) {
        $state = $transitions[$state];
        if ($state == 'idle') {
            break;
        }
    }
}
state_machine();
?>