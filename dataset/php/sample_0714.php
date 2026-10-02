<?php
function rotate_point($x, $y, $z, $angle, $axis) {
    if ($axis == 'x') {
        return array($x, $y * cos($angle) - $z * sin($angle), $y * sin($angle) + $z * cos($angle));
    } elseif ($axis == 'y') {
        return array($x * cos($angle) + $z * sin($angle), $y, -$x * sin($angle) + $z * cos($angle));
    } elseif ($axis == 'z') {
        return array($x * cos($angle) - $y * sin($angle), $x * sin($angle) + $y * cos($angle), $z);
    }
}

function transform_3d($points, $angle, $axis, $depth=0) {
    if (empty($points) || $depth > 2) {
        return array();
    }
    $transformed = array_map(function($p) use ($angle, $axis) {
        return rotate_point($p[0], $p[1], $p[2], $angle, $axis);
    }, $points);
    return array($transformed) + transform_3d($transformed, $angle, $axis, $depth + 1);
}

function main() {
    $points = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $angle = 90;
    $axis = 'z';
    $result = transform_3d($points, $angle, $axis);
    print_r($result);
}

main();
?>