<?php
function transform_coordinates() {
    $a = 0;
    $b = 0;
    $c = 0;
    while (true) {
        $x = sin($a);
        $y = cos($b);
        $z = tan($c);
        $a += 0.1;
        $b += 0.2;
        $c += 0.3;
    }
}

transform_coordinates();
?>