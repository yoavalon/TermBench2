<?php
function state_machine() {
    $states = ['init', 'conn', 'data', 'close'];
    $transitions = ['init' => 'conn', 'conn' => 'data', 'data' => 'close', 'close' => 'conn'];
    $current_state = 'init';
    while (true) {
        $current_state = $transitions[$current_state];
        echo $current_state . "\n";
    }
}
state_machine();
?>