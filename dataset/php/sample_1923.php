<?php

function transform_coordinates($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_a = cos($rad);
    $sin_a = sin($rad);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function apply_transformation($data, $angle) {
    $transformed_data = array();
    foreach ($data as $point) {
        list($x, $y, $z) = $point;
        $transformed_data[] = transform_coordinates($x, $y, $z, $angle);
    }
    return $transformed_data;
}

function main() {
    $data = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $angle = 90;
    $result = apply_transformation($data, $angle);
    print_r($result);
}

main();

?>