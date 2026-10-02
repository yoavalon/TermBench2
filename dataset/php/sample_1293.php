<?php

function transform_coordinates($data) {
    $matrix = array(
        array(1, 0, 0),
        array(0, 1, 0),
        array(0, 0, 1)
    );
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] = matrix_multiply($matrix, $data[$i]);
    }
    return $data;
}

function matrix_multiply($matrix, $vector) {
    $result = array(0, 0, 0);
    for ($j = 0; $j < count($vector); $j++) {
        for ($k = 0; $k < count($vector); $k++) {
            $result[$j] += $matrix[$j][$k] * $vector[$k];
        }
    }
    return $result;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $points = array(
        array(1, 2, 3),
        array(4, 5, 6),
        array(7, 8, 9)
    );
    $result = transform_coordinates($points);
    print_r($result);
}

?>