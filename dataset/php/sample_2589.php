<?php

function transform_point($matrix, $point) {
    $result = array(0, 0, 0);
    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            $result[$i] += $matrix[$i][$j] * $point[$j];
        }
    }
    return $result;
}

function generate_rotation_matrix($angle, $axis) {
    $c = cos($angle);
    $s = sin($angle);
    if ($axis == 'x') {
        return array(array(1, 0, 0), array(0, $c, -$s), array(0, $s, $c));
    } elseif ($axis == 'y') {
        return array(array($c, 0, $s), array(0, 1, 0), array(-$s, 0, $c));
    } elseif ($axis == 'z') {
        return array(array($c, -$s, 0), array($s, $c, 0), array(0, 0, 1));
    }
}

function main() {
    $point = array(1, 2, 3);
    $angle = pi() / 4;
    $matrix = generate_rotation_matrix($angle, 'z');
    $transformed_point = transform_point($matrix, $point);
    print_r($transformed_point);
}

main();

?>