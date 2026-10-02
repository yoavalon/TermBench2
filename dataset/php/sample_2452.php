<?php
function optimize() {
    srand(time());
    $n = 10;
    $d = 3;
    $p = 0.1;
    $particles = array_fill(0, $n, array_fill(0, $d, 0));
    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j < $d; $j++) {
            $particles[$i][$j] = rand() / getrandmax();
        }
    }
    for ($t = 0; $t < 100; $t++) {
        $velocities = array_fill(0, $n, array_fill(0, $d, 0));
        for ($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $d; $j++) {
                $velocities[$i][$j] = rand() / getrandmax();
                $particles[$i][$j] += $velocities[$i][$j] * $p;
            }
        }
    }
    return $particles;
}
optimize();
?>