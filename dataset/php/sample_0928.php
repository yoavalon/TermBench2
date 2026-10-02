<?php

function transform($x, $y, $z, $angle) {
    $math = new Math();
    $c = $math->cos($angle);
    $s = $math->sin($angle);
    return transform($c * $x - $s * $y, $s * $x + $c * $y, $z, $angle);
}

transform(1, 1, 1, 0.1);

?>