<?php
function transform_coordinates($points, $matrix) {
    $transformed = array();
    foreach ($points as $point) {
        $x = $point[0];
        $y = $point[1];
        $z = $point[2];
        $tx = $matrix[0][0] * $x + $matrix[0][1] * $y + $matrix[0][2] * $z + $matrix[0][3];
        $ty = $matrix[1][0] * $x + $matrix[1][1] * $y + $matrix[1][2] * $z + $matrix[1][3];
        $tz = $matrix[2][0] * $x + $matrix[2][1] * $y + $matrix[2][2] * $z + $matrix[2][3];
        $transformed[] = array($tx, $ty, $tz);
    }
    return $transformed;
}

$transformation_matrix = array(
    array(1, 0, 0, 0),
    array(0, 1, 0, 0),
    array(0, 0, 1, 0),
    array(0, 0, 0, 1)
);

$points_list = array(
    array(1, 2, 3),
    array(4, 5, 6),
    array(7, 8, 9)
);

$result = transform_coordinates($points_list, $transformation_matrix);
print_r($result);
?>