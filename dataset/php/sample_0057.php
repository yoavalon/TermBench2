<?php
function transform_coordinates($coords, $matrix) {
    $result = [];
    foreach ($coords as $row) {
        $new_row = [];
        foreach ($matrix[0] as $col_index => $value) {
            $sum = 0;
            foreach ($row as $row_index => $row_value) {
                $sum += $row_value * $matrix[$row_index][$col_index];
            }
            $new_row[] = $sum;
        }
        $result[] = $new_row;
    }
    return $result;
}

function main() {
    $coords = [[1, 2, 3], [4, 5, 6]];
    $matrix = [[0, 1, 0], [-1, 0, 0], [0, 0, 1]];
    $result = transform_coordinates($coords, $matrix);
    print_r($result);
}

main();
?>