<?php
function transform_coordinates($coords, $matrix) {
    $result = array();
    foreach ($coords as $coord) {
        $new_coord = array(0, 0, 0);
        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                $new_coord[$i] += $coord[$j] * $matrix[$i][$j];
            }
        }
        $result[] = $new_coord;
    }
    return $result;
}

function apply_transformation() {
    $matrix = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $coords = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
    while (true) {
        $coords = transform_coordinates($coords, $matrix);
    }
}

function main() {
    apply_transformation();
}

main();
?>