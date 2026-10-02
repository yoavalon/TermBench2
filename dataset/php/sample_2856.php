<?php

function transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z) {
    $cx = cos($angle_x);
    $sx = sin($angle_x);
    $cy = cos($angle_y);
    $sy = sin($angle_y);
    $cz = cos($angle_z);
    $sz = sin($angle_z);
    $x_new = $x * $cy * $cz + $y * ($sx * $sy * $cz - $cx * $sz) + $z * ($cx * $sy * $cz + $sx * $sz);
    $y_new = $x * $cy * $sz + $y * ($sx * $sy * $sz + $cx * $cz) + $z * ($cx * $sy * $sz - $sx * $cz);
    $z_new = -$x * $sy + $y * $sx * $cy + $z * $cx * $cy;
    return array($x_new, $y_new, $z_new);
}

function rotate_point() {
    $x = 1.0;
    $y = 2.0;
    $z = 3.0;
    $angle_x = 0.1;
    $angle_y = 0.2;
    $angle_z = 0.3;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z);
        echo "($x, $y, $z)\n";
    }
}

rotate_point();

?>