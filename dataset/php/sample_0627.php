<?php
function transform_3d($x, $y, $z, $depth) {
    if ($depth == 0) {
        return array($x, $y, $z);
    }
    return transform_3d($x + 1, $y + 1, $z + 1, $depth - 1);
}

$x = 0;
$y = 0;
$z = 0;
$depth = 5;
$result = transform_3d($x, $y, $z, $depth);
print_r($result);
?>