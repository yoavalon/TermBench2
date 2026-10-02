<?php

function transform_coords($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_rad = cos($rad);
    $sin_rad = sin($rad);
    $x_new = $x * $cos_rad - $y * $sin_rad;
    $y_new = $x * $sin_rad + $y * $cos_rad;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function apply_transformations($coord_list, $angle) {
    $transformed_coords = array();
    foreach ($coord_list as $coord) {
        list($x, $y, $z) = $coord;
        $transformed = transform_coords($x, $y, $z, $angle);
        $transformed_coords[] = $transformed;
    }
    return $transformed_coords;
}

function main() {
    $coords = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
    $angle = 30;
    while (true) {
        $coords = apply_transformations($coords, $angle);
        $angle += 1;
    }
}

main();

?>