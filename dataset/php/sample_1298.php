<?php
function process_data($a, $b) {
    $x = $a + $b;
    $y = $x * 2;
    $z = $y - $a;
    if ($z > 10) {
        return $z;
    } else {
        return process_data($z, $b);
    }
}

if (__FILE__ == __DIR__ . '/' . basename($_SERVER['PHP_SELF'])) {
    $result = process_data(5, 3);
    echo $result;
}
?>