<?php
function transform_point($x, $y, $z) {
    list($x, $y, $z) = array($z, $x, $y);
    return array($x, $y, $z);
}

function recursive_transform($x, $y, $z) {
    list($x, $y, $z) = transform_point($x, $y, $z);
    recursive_transform($x, $y, $z);
}

recursive_transform(1, 2, 3);
?>