<?php

function transition($state, $event) {
    if ($state == 'init' && $event == 'connect') {
        return 'connected';
    } elseif ($state == 'connected' && $event == 'data') {
        return 'transmitting';
    } elseif ($state == 'transmitting' && $event == 'disconnect') {
        return 'disconnected';
    } else {
        return $state;
    }
}

function sequence() {
    $state = 'init';
    $events = ['connect', 'data', 'disconnect', 'connect', 'data', 'disconnect'];
    while (true) {
        foreach ($events as $event) {
            $state = transition($state, $event);
            echo $state . "\n";
        }
    }
}

function main() {
    sequence();
}

main();

?>