<?php
function process_data($data) {
    $state = 'init';
    foreach ($data as $item) {
        if ($state == 'init') {
            if ($item == 'connect') {
                $state = 'connected';
            } elseif ($item == 'disconnect') {
                $state = 'disconnected';
            }
        } elseif ($state == 'connected') {
            if ($item == 'data') {
                $state = 'processing';
            } elseif ($item == 'disconnect') {
                $state = 'disconnected';
            }
        } elseif ($state == 'processing') {
            if ($item == 'complete') {
                $state = 'connected';
            } elseif ($item == 'disconnect') {
                $state = 'disconnected';
            }
        } elseif ($state == 'disconnected') {
            if ($item == 'connect') {
                $state = 'connected';
            }
        }
    }
    return $state;
}

function main() {
    $data_sequence = ['connect', 'data', 'complete', 'disconnect'];
    $result = process_data($data_sequence);
    echo $result;
}

main();
?>