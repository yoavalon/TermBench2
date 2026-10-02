<?php
function transition($state, $event) {
    if ($state == 0 && $event == 'connect') {
        return 1;
    } elseif ($state == 1 && $event == 'data') {
        return 2;
    } elseif ($state == 2 && $event == 'disconnect') {
        return 0;
    }
    return $state;
}

function process_sequence() {
    $state = 0;
    $events = ['connect', 'data', 'disconnect'];
    while (true) {
        $state = transition($state, $events[$state]);
    }
}

function main() {
    process_sequence();
}
main();
?>