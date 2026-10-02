<?php
function transform_coordinates($x, $y, $z, $a, $b, $c) {
    $x_new = $x + $a;
    $y_new = $y + $b;
    $z_new = $z + $c;
    return array($x_new, $y_new, $z_new);
}

list($x, $y, $z, $a, $b, $c) = array(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
list($x_new, $y_new, $z_new) = transform_coordinates($x, $y, $z, $a, $b, $c);
echo 'Transformed coordinates: (' . $x_new . ', ' . $y_new . ', ' . $z_new . ')';
?>