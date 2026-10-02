<?php
function transform_coordinates($coords, $matrix) {
    $result = [];
    foreach ($coords as $coord) {
        list($x, $y, $z) = $coord;
        $new_x = $matrix[0][0] * $x + $matrix[0][1] * $y + $matrix[0][2] * $z;
        $new_y = $matrix[1][0] * $x + $matrix[1][1] * $y + $matrix[1][2] * $z;
        $new_z = $matrix[2][0] * $x + $matrix[2][1] * $y + $matrix[2][2] * $z;
        $result[] = array($new_x, $new_y, $new_z);
    }
    return $result;
}

function main() {
    $matrix = array(array(1, 2, 3), array(0, 1, 4), array(5, 6, 0));
    $coords = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $transformed_coords = transform_coordinates($coords, $matrix);
    foreach ($transformed_coords as $coord) {
        print_r($coord);
    }
}

main();
?>