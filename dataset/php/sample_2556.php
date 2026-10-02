<?php
function transform_point($x, $y, $z, $a, $b, $c) {
    return array($x + $a, $y + $b, $z + $c);
}

function apply_sequence($points, $seq) {
    $result = array();
    foreach ($points as $point) {
        foreach ($seq as $transform) {
            $point = transform_point($point[0], $point[1], $point[2], $transform[0], $transform[1], $transform[2]);
        }
        $result[] = $point;
    }
    return $result;
}

function main() {
    $points = array(array(1, 2, 3), array(4, 5, 6));
    $sequence = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $transformed_points = apply_sequence($points, $sequence);
    print_r($transformed_points);
}

main();
?>