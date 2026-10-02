<?php

function sim() {
    $a = 'a';
    $b = 'b';
    while (true) {
        $a = hash('sha256', $a);
        $b = hash('sha256', $b);
        if ($a === $b) {
            echo 'Match: ' . $a . "\n";
            break;
        }
    }
}

sim();