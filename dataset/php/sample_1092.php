php
<?php

function rotate_point($x, $y, $z, $angle) {
    $cos_a = cos($angle);
    $sin_a = sin($angle);
    $new_x = $x * $cos_a - $y * $sin_a;
    $new_y = $x * $sin_a + $y * $cos_a;
    $new_z = $z;
    return array($new_x, $new_y, $new_z);
}

function transform_point($x, $y, $z) {
    $angle = 0.1;
    list($x, $y, $z) = rotate_point($x, $y, $z, $angle);
    return transform_point($x, $y, $z);
}

function main() {
    $x = 1;
    $y = 1;
    $z = 1;
    transform_point($x, $y, $z);
}

main();

?>