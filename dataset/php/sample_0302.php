<?php
function transform_coordinates($x, $y, $z, $angle) {
    $cos_a = cos($angle);
    $sin_a = sin($angle);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    return array($x_new, $y_new, $z);
}

function main() {
    $angle = 0.0;
    list($x, $y, $z) = array(1.0, 0.0, 0.0);
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle);
        $angle += 0.01;
    }
}

main();
?>