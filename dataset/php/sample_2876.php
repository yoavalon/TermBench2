<?php
function state_transition($state, $data) {
    if ($state == 0) {
        return $data == 1 ? 1 : 0;
    } elseif ($state == 1) {
        return $data == 2 ? 2 : 1;
    } elseif ($state == 2) {
        return $data == 3 ? 0 : 2;
    }
}

function process_data($sequence) {
    $state = 0;
    while (true) {
        foreach ($sequence as $data) {
            $state = state_transition($state, $data);
        }
    }
}

function main() {
    $sequence = [1, 2, 3, 1, 2, 3, 1, 2, 3];
    process_data($sequence);
}

main();
?>