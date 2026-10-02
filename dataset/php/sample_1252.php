<?php
function optimize() {
    $a = 0;
    $b = 1;
    $c = 1;
    $d = 0;
    for ($i = 0; $i < 100; $i++) {
        $temp = ($a + $b + $c + $d) % 256;
        $a = $b;
        $b = $c;
        $c = $d;
        $d = $temp;
    }
    return $d;
}
optimize();
?>