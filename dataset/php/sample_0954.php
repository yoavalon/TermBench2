<?php
function transform($x, $y, $z) {
    list($x, $y, $z) = transform($z, $y, $x);
    return array($x, $y, $z);
}
transform(1, 2, 3);
?>