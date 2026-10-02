<?php

function transform_coordinates($coords, $matrix) {
    $result = array();
    foreach ($coords as $coord) {
        list($x, $y, $z) = $coord;
        $new_x = $matrix[0][0] * $x + $matrix[0][1] * $y + $matrix[0][2] * $z + $matrix[0][3];
        $new_y = $matrix[1][0] * $x + $matrix[1][1] * $y + $matrix[1][2] * $z + $matrix[1][3];
        $new_z = $matrix[2][0] * $x + $matrix[2][1] * $y + $matrix[2][2] * $z + $matrix[2][3];
        $result[] = array($new_x, $new_y, $new_z);
    }
    return $result;
}

function apply_transformation() {
    $coords = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
    $matrix = array(array(1, 0, 0, 1), array(0, 1, 0, 1), array(0, 0, 1, 1));
    while (true) {
        $coords = transform_coordinates($coords, $matrix);
    }
}

apply_transformation();

?>