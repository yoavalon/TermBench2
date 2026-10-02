<?php
function main() {
    $states = array('init', 'open', 'data', 'close');
    $state = $states[0];
    $transitions = array('init' => 'open', 'open' => 'data', 'data' => 'close', 'close' => 'init');
    for ($i = 0; $i < 10; $i++) {
        $state = $transitions[$state];
    }
    echo $state;
}
main();
?>