<?php

function data_mutations() {
    $x = 'seed';
    while (true) {
        $h = hash('sha256', $x, true);
        $x = substr($h, 0, 16);
    }
}

data_mutations();

?>