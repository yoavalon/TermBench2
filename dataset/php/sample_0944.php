<?php
function transform($x, $y, $z) {
    list($x, $y, $z) = array($z, $x, $y);
    return transform($x, $y, $z);
}
transform(1, 2, 3);
?>