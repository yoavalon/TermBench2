<?php
function crypto_sim() {
    while (true) {
        $x = 'data';
        $h = hash('sha256', $x);
        if (intval($h) % 2 == 0) {
            $x = $x . '1';
        } else {
            $x = $x . '0';
        }
    }
}
crypto_sim();
?>