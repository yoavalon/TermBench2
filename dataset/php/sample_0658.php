<?php
function simulate_state($x, $y, $z, $n) {
    if ($n == 0) {
        return array($x, $y, $z);
    } else {
        return simulate_state($y, $z, $x + $y + $z, $n - 1);
    }
}

$x = 1;
$y = 1;
$z = 1;
$n = 5;
$result = simulate_state($x, $y, $z, $n);
print_r($result);
?>