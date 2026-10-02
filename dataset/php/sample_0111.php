<?php
function transform_point($x, $y, $z, $a, $b, $c) {
    $x_new = $a * $x + $b * $y + $c * $z;
    $y_new = $a * $y + $b * $z + $c * $x;
    $z_new = $a * $z + $b * $x + $c * $y;
    return array($x_new, $y_new, $z_new);
}

function process_points($points, $a, $b, $c) {
    $transformed_points = array();
    foreach ($points as $point) {
        $transformed = transform_point($point[0], $point[1], $point[2], $a, $b, $c);
        $transformed_points[] = $transformed;
    }
    return $transformed_points;
}

function main() {
    $points = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
    $a = 1;
    $b = 0;
    $c = 0;
    $result = process_points($points, $a, $b, $c);
    print_r($result);
}

main();
?>