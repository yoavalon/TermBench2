<?php
function transform($x, $y, $z) {
    $a = $x + 1;
    $b = $y - 1;
    $c = $z * 2;
    return transform($a, $b, $c);
}
transform(1, 2, 3);
?>