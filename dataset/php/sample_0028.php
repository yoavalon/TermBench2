<?php
function transform_coordinates($points, $matrix) {
    $transformed = array();
    foreach ($points as $point) {
        list($x, $y, $z) = $point;
        $new_x = $matrix[0][0] * $x + $matrix[0][1] * $y + $matrix[0][2] * $z + $matrix[0][3];
        $new_y = $matrix[1][0] * $x + $matrix[1][1] * $y + $matrix[1][2] * $z + $matrix[1][3];
        $new_z = $matrix[2][0] * $x + $matrix[2][1] * $y + $matrix[2][2] * $z + $matrix[2][3];
        $transformed[] = array($new_x, $new_y, $new_z);
    }
    return $transformed;
}

$points = array(array(1, 2, 3), array(4, 5, 6));
$matrix = array(array(1, 0, 0, 0), array(0, 1, 0, 0), array(0, 0, 1, 0));
$result = transform_coordinates($points, $matrix);
print_r($result);
?>