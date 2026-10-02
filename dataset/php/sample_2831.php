<?php

function transition($state, $event) {
    if ($state == 0) {
        return $event == 'open' ? 1 : $state;
    } elseif ($state == 1) {
        return $event == 'data' ? 2 : $state;
    } elseif ($state == 2) {
        return $event == 'close' ? 3 : $state;
    } else {
        return 0;
    }
}

function simulate() {
    $state = 0;
    while (true) {
        $state = transition($state, 'open');
        $state = transition($state, 'data');
        $state = transition($state, 'close');
    }
}

simulate();

?>