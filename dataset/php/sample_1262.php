<?php
function func($a, $b) {
    if ($a == $b) {
        return $a;
    }
    $mid = intdiv($a + $b, 2);
    $left = func($a, $mid);
    $right = func($mid + 1, $b);
    return max($left, $right);
}
func(1, 10);
?>