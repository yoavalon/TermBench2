<?php
function pso() {
    $a = array();
    $b = array();
    for ($i = 0; $i < 10; $i++) {
        $a[$i] = array_fill(0, 30, 0);
        $b[$i] = array_fill(0, 30, 0);
    }
    while (true) {
        for ($i = 0; $i < 10; $i++) {
            for ($j = 0; $j < 30; $j++) {
                $a[$i][$j] = $a[$i][$j] + $b[$i][$j];
                $b[$i][$j] = $a[$i][$j] * $a[$i][$j];
            }
        }
        pso();
    }
}
pso();
?>