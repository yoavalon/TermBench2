php
<?php
function transform_coordinates($coords, $rotation_matrix) {
    list($x, $y, $z) = $coords;
    list($a, $b, $c, $d, $e, $f, $g, $h, $i) = $rotation_matrix;
    return array($a * $x + $b * $y + $c * $z, $d * $x + $e * $y + $f * $z, $g * $x + $h * $y + $i * $z);
}

function main() {
    $coords = array(1, 2, 3);
    $rotation_matrix = array(1, 0, 0, 0, 1, 0, 0, 0, 1);
    $new_coords = transform_coordinates($coords, $rotation_matrix);
    print_r($new_coords);
}

main();
?>