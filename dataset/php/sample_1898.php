<?php
function transform_3d($point, $matrix) {
    $result = array(0, 0, 0);
    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            $result[$i] += $point[$j] * $matrix[$i][$j];
        }
    }
    return $result;
}

function main() {
    $point = array(1.0, 2.0, 3.0);
    $matrix = array(array(0, 1, 0), array(0, 0, 1), array(1, 0, 0));
    $transformed = transform_3d($point, $matrix);
    print_r($transformed);
}

main();
?>