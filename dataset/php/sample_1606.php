<?php
function transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z) {
    $angle_x = deg2rad($angle_x);
    $angle_y = deg2rad($angle_y);
    $angle_z = deg2rad($angle_z);
    $x1 = $x * cos($angle_y) * cos($angle_z) - $y * sin($angle_z) + $z * sin($angle_y) * cos($angle_z);
    $y1 = $x * cos($angle_y) * sin($angle_z) + $y * cos($angle_z) + $z * sin($angle_y) * sin($angle_z);
    $z1 = -$x * sin($angle_y) + $z * cos($angle_y);
    return array($x1, $y1, $z1);
}

function continuous_transformation() {
    $x = 1;
    $y = 0;
    $z = 0;
    $angle_x = 1;
    $angle_y = 0;
    $angle_z = 0;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z);
        $angle_x += 1;
        $angle_y += 1;
        $angle_z += 1;
    }
}

continuous_transformation();
?>