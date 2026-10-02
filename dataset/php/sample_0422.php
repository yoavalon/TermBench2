<?php

function transition($state) {
    if ($state == 'A') {
        return 'B';
    } elseif ($state == 'B') {
        return 'C';
    } elseif ($state == 'C') {
        return 'A';
    } else {
        return 'A';
    }
}

function process($state) {
    while (true) {
        $state = transition($state);
        echo $state . "\n";
    }
}

function main() {
    $initial_state = 'A';
    process($initial_state);
}

main();

?>