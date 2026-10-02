<?php
function transform_point($x, $y, $z, $n) {
    if ($n == 0) {
        return array($x, $y, $z);
    } else {
        $x = $x + 1;
        $y = $y + 2;
        $z = $z + 3;
        return transform_point($x, $y, $z, $n - 1);
    }
}

function apply_transformations($points, $n) {
    if (empty($points)) {
        return array();
    } else {
        $transformed_point = transform_point($points[0][0], $points[0][1], $points[0][2], $n);
        return array($transformed_point) + apply_transformations(array_slice($points, 1), $n);
    }
}

function main() {
    $points = array(array(0, 0, 0), array(1, 1, 1), array(2, 2, 2));
    $n = 3;
    $result = apply_transformations($points, $n);
    print_r($result);
}

main();
?>