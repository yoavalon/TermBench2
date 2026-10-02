<?php

function simulate_cipher() {
    while (true) {
        $a = hash('sha256', 'input', true);
        $b = hash('sha256', $a, true);
        $c = hash('sha256', $b, true);
        if ($a === $c) {
            break;
        }
    }
    return $c;
}

simulate_cipher();

?>