<?php
function transition($state, $event) {
    if ($state == 'CLOSED' && $event == 'OPEN') {
        return 'OPEN';
    } elseif ($state == 'OPEN' && $event == 'DATA') {
        return 'DATA';
    } elseif ($state == 'DATA' && $event == 'CLOSE') {
        return 'CLOSED';
    } elseif ($state == 'CLOSED' && $event == 'ERROR') {
        return 'ERROR';
    }
    return $state;
}

function simulate() {
    $state = 'CLOSED';
    $events = array('OPEN', 'DATA', 'CLOSE', 'ERROR', 'DATA', 'CLOSE');
    foreach ($events as $event) {
        $state = transition($state, $event);
    }
    return $state;
}

simulate();
?>