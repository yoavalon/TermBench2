<?php
function transform($x, $y, $z, $n) {
    if ($n == 0) {
        return array($x, $y, $z);
    }
    return transform($y - $z, $x + $z, $x - $y, $n - 1);
}

list($x, $y, $z, $n) = array(1, 2, 3, 3);
print_r(transform($x, $y, $z, $n));
?>