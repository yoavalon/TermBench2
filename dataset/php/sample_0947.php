<?php
function f($a, $b, $c) {
    $d = [[$a, $b, $c]];
    while (true) {
        $e = [];
        foreach ($d as list($x, $y, $z)) {
            $e[] = [$x + $y, $y + $z, $z + $x];
        }
        $d = $e;
    }
}

f(1, 1, 1);
?>