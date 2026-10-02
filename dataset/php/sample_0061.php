<?php
function state_machine() {
    $states = ['init', 'open', 'data', 'close'];
    $state = $states[0];
    $transitions = ['init' => 'open', 'open' => 'data', 'data' => 'close', 'close' => 'init'];
    while ($state != 'close') {
        $state = $transitions[$state];
    }
    return $state;
}
state_machine();
?>