<?php
function transform_coordinates($x, $y, $z, $matrix) {
    $x_new = $matrix[0][0] * $x + $matrix[0][1] * $y + $matrix[0][2] * $z;
    $y_new = $matrix[1][0] * $x + $matrix[1][1] * $y + $matrix[1][2] * $z;
    $z_new = $matrix[2][0] * $x + $matrix[2][1] * $y + $matrix[2][2] * $z;
    return array($x_new, $y_new, $z_new);
}

function apply_transformations($coord_list, $matrix_list) {
    $transformed_coords = array();
    foreach ($coord_list as $coord) {
        foreach ($matrix_list as $matrix) {
            $coord = transform_coordinates($coord[0], $coord[1], $coord[2], $matrix);
        }
        array_push($transformed_coords, $coord);
    }
    return $transformed_coords;
}

function main() {
    $coords = array(array(1, 2, 3), array(4, 5, 6));
    $matrices = array(array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1)), array(array(0, 0, 1), array(1, 0, 0), array(0, 1, 0)));
    $result = apply_transformations($coords, $matrices);
    print_r($result);
}

main();
?>