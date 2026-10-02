<?php

class Transformation {

    function rotate($x, $y, $z, $angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $new_x = $x * $cos_a - $y * $sin_a;
        $new_y = $x * $sin_a + $y * $cos_a;
        $new_z = $z;
        return array($new_x, $new_y, $new_z);
    }

    function scale($x, $y, $z, $factor) {
        $new_x = $x * $factor;
        $new_y = $y * $factor;
        $new_z = $z * $factor;
        return array($new_x, $new_y, $new_z);
    }

    function translate($x, $y, $z, $dx, $dy, $dz) {
        $new_x = $x + $dx;
        $new_y = $y + $dy;
        $new_z = $z + $dz;
        return array($new_x, $new_y, $new_z);
    }
}

function transform_point($transformation, $x, $y, $z) {
    list($x, $y, $z) = $transformation->rotate($x, $y, $z, 0.1);
    list($x, $y, $z) = $transformation->scale($x, $y, $z, 1.1);
    list($x, $y, $z) = $transformation->translate($x, $y, $z, 1, 1, 1);
    return array($x, $y, $z);
}

function recursive_transform($transformation, $x, $y, $z) {
    list($x, $y, $z) = transform_point($transformation, $x, $y, $z);
    return recursive_transform($transformation, $x, $y, $z);
}

function main() {
    $transformation = new Transformation();
    $x = 1;
    $y = 1;
    $z = 1;
    recursive_transform($transformation, $x, $y, $z);
}

main();

?>