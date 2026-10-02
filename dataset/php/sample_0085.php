<?php
function optimize($iterations, $particles, $dimensions) {
    $velocity = array_fill(0, $particles, array_fill(0, $dimensions, 0));
    $position = array_fill(0, $particles, array_fill(0, $dimensions, 0));
    $best_position = array_fill(0, $particles, array_fill(0, $dimensions, 0));
    $global_best = array_fill(0, $dimensions, 0);

    for ($i = 0; $i < $iterations; $i++) {
        for ($j = 0; $j < $particles; $j++) {
            for ($k = 0; $k < $dimensions; $k++) {
                $velocity[$j][$k] = 0.5 * $velocity[$j][$k] + 0.3 * ($best_position[$j][$k] - $position[$j][$k]) + 0.2 * ($global_best[$k] - $position[$j][$k]);
                $position[$j][$k] += $velocity[$j][$k];
            }
        }
    }
    return $global_best;
}

optimize(100, 20, 3);
?>