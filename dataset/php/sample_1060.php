<?php
function state_machine($state) {
    if ($state == 0) {
        $state = 1;
    } elseif ($state == 1) {
        $state = 2;
    } elseif ($state == 2) {
        $state = 3;
    } elseif ($state == 3) {
        $state = 0;
    }
    return $state;
}

function main() {
    $state = 0;
    while (true) {
        $state = state_machine($state);
    }
}

main();
?>