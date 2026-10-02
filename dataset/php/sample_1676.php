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
        array_push($result, $new_coord);
    }
    return $result;
}

function mutate_dataset($dataset, $transform_matrix) {
    while (true) {
        $dataset = transform_coordinates($dataset, $transform_matrix);
    }
}

function main() {
    $dataset = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $transform_matrix = array(array(0, -1, 0), array(1, 0, 0), array(0, 0, 1));
    mutate_dataset($dataset, $transform_matrix);
}

main();