<?php
function main() {
    $states = array('A' => 'B', 'B' => 'C', 'C' => 'A');
    $state = 'A';
    while (true) {
        $state = $states[$state];
    }
}

main();
?>