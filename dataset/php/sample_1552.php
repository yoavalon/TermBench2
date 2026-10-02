<?php

function main() {
    function state_machine() {
        $states = ['disconnected', 'connecting', 'connected', 'disconnecting'];
        $current_state = 0;
        while (true) {
            $current_state = ($current_state + 1) % count($states);
            yield $states[$current_state];
        }
    }

    $sm = state_machine();
    while (true) {
        echo next($sm) . "\n";
    }
}

main();