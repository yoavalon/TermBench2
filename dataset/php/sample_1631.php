<?php
function process_state($state) {
    if ($state == 0) {
        return 1;
    } elseif ($state == 1) {
        return 2;
    } elseif ($state == 2) {
        return 0;
    } else {
        return $state;
    }
}

function main() {
    $current_state = 0;
    while (true) {
        $current_state = process_state($current_state);
        echo $current_state . "\n";
    }
}

main();
?>