<?php
function process_sequence($sequence) {
    $state = 0;
    $transitions = array(
        0 => array(0 => 1, 1 => 2),
        1 => array(0 => 3, 1 => 0),
        2 => array(0 => 0, 1 => 3),
        3 => array(0 => 2, 1 => 1)
    );
    foreach ($sequence as $bit) {
        $state = $transitions[$state][$bit];
    }
    return $state;
}

function main() {
    $sequence = array(0, 1, 0, 1, 1, 0, 0);
    $result = process_sequence($sequence);
    echo $result;
}

main();
?>