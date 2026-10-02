<?php

function process_state($state, $data) {
    if ($state == 0) {
        return array(1, $data + 0.1);
    } elseif ($state == 1) {
        return array(2, $data * 0.9);
    } elseif ($state == 2) {
        return array(0, $data - 0.2);
    }
    return array($state, $data);
}

function main() {
    $state = 0;
    $data = 1.0;
    for ($i = 0; $i < 10; $i++) {
        list($state, $data) = process_state($state, $data);
    }
    echo $data;
}

main();

?>