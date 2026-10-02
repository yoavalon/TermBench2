<?php

function simulate_cipher() {
    $a = 'initial data';
    while (true) {
        $a = hash('sha256', $a, true);
    }
}

simulate_cipher();