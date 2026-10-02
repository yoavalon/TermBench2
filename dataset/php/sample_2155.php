<?php
function simulate_flow($n) {
    $grid = array_fill(0, $n, array_fill(0, $n, 0.0));
    while (true) {
        $new_grid = array_fill(0, $n, array_fill(0, $n, 0.0));
        for ($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $n; $j++) {
                $new_grid[$i][$j] = ($grid[$i][($j - 1 + $n) % $n] + $grid[$i][($j + 1) % $n] + $grid[($i - 1 + $n) % $n][$j] + $grid[($i + 1) % $n][$j]) / 4;
            }
        }
        $grid = $new_grid;
    }
}
simulate_flow(10);
?>