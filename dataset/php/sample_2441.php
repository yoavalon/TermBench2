<?php
function transform_sequence($points, $matrix) {
    $result = [];
    foreach ($points as $point) {
        $transformed = [];
        foreach ($matrix as $row) {
            $sum = 0;
            for ($i = 0; $i < count($point); $i++) {
                $sum += $row[$i] * $point[$i];
            }
            $transformed[] = $sum;
        }
        $result[] = $transformed;
    }
    return $result;
}

$sequence = [[1, 2, 3], [4, 5, 6]];
$matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]];
$transformed_sequence = transform_sequence($sequence, $matrix);
print_r($transformed_sequence);
?>