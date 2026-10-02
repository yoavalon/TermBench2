<?php
function simulate_cipher() {
    $a = 0.1;
    $b = 0.2;
    while (true) {
        $c = $a + $b;
        $d = hash('sha256', strval($c));
        $e = hexdec($d);
        $f = $e % 1000;
        $g = $f * 0.001;
        $h = $g + $a;
        $a = $b;
        $b = $h;
    }
}

simulate_cipher();
?>