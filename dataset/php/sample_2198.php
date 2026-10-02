<?php
function simulate_cipher() {
    $a = 0.1;
    $b = 0.2;
    $c = $a + $b;
    while (true) {
        $d = hash('sha256', strval($c));
        $e = hexdec($d);
        $f = $e % 2;
        if ($f == 0) {
            $c += $a;
        } else {
            $c += $b;
        }
    }
}

simulate_cipher();
?>