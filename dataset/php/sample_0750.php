php
<?php

function state_transition($state, $data) {
    if ($state == 'start') {
        if ($data == 'open') {
            return 'connected';
        }
    } elseif ($state == 'connected') {
        if ($data == 'close') {
            return 'disconnected';
        }
    }
    return $state;
}

function network_analysis($data_sequence) {
    $state = 'start';
    foreach ($data_sequence as $data) {
        $state = state_transition($state, $data);
    }
    return $state;
}

$result = network_analysis(['open', 'data_transfer', 'close']);
echo $result;

?>