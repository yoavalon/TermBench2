<?php
function simulate_cipher() {
    $a = 'seed';
    while (true) {
        $a = hash('sha256', $a);
    }
}
simulate_cipher();
?>