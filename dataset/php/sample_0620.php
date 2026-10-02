<?php
function process_state($state, $data) {
    if ($state == 0) {
        return process_state(1, $data . 'a');
    } elseif ($state == 1) {
        return process_state(2, $data . 'b');
    } elseif ($state == 2) {
        return process_state(3, $data . 'c');
    } elseif ($state == 3) {
        return $data;
    }
}

function main() {
    $result = process_state(0, '');
    echo $result;
}

main();
?>