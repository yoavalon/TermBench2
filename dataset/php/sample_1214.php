<?php
function process() {
    $states = ['init', 'connect', 'data_exchange', 'disconnect', 'done'];
    $transitions = ['init' => 'connect', 'connect' => 'data_exchange', 'data_exchange' => 'disconnect', 'disconnect' => 'done'];
    $currentState = $states[0];
    while ($currentState != $states[count($states) - 1]) {
        $currentState = $transitions[$currentState];
    }
    echo 'Process terminated';
}

process();
?>