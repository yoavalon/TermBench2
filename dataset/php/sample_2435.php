<?php
function f($x) {
    $a = 0;
    $b = 1;
    $c = 1;
    for ($i = 0; $i < $x; $i++) {
        $a = $b;
        $b = $c;
        $c = $a + $b + $c;
    }
    return $a;
}
if (__FILE__ == __DIR__ . '/' . basename($_SERVER['PHP_SELF'])) {
    f(10);
}
?>