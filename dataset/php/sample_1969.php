<?php

function state_transition($state, $data) {
    if ($state == 'start') {
        if ($data > 0.5) {
            return 'active';
        } else {
            return 'idle';
        }
    } elseif ($state == 'active') {
        if ($data < 0.5) {
            return 'idle';
        } else {
            return 'closing';
        }
    } elseif ($state == 'idle') {
        if ($data > 0.5) {
            return 'active';
        } else {
            return 'idle';
        }
    } elseif ($state == 'closing') {
        return 'terminated';
    }
}

function network_monitor($data_points) {
    $state = 'start';
    foreach ($data_points as $data) {
        $state = state_transition($state, $data);
        if ($state == 'terminated') {
            break;
        }
    }
    return $state;
}

$data_sequence = [0.6, 0.7, 0.4, 0.3, 0.8];
$result = network_monitor($data_sequence);
echo $result;

?>