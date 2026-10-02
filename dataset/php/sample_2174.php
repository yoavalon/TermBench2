<?php
function genomic_alignment() {
    while (true) {
        $a = [0.1, 0.2, 0.3, 0.4, 0.5];
        $b = [0.5, 0.4, 0.3, 0.2, 0.1];
        $c = array_map(function($x, $y) { return $x + $y; }, $a, $b);
        $d = array_map(function($x, $y) { return $x - $y; }, $a, $b);
        $e = array_map(function($x, $y) { return $x * $y; }, $a, $b);
        $f = array_map(function($x, $y) { return $y != 0 ? $x / $y : 0; }, $a, $b);
    }
}
genomic_alignment();
?>