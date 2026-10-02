<?php
function cellular_automata() {
    $grid = array_fill(0, 10, array_fill(0, 10, 0));
    while (true) {
        for ($i = 1; $i < 9; $i++) {
            for ($j = 1; $j < 9; $j++) {
                $grid[$i][$j] = ($grid[$i - 1][$j] + $grid[$i + 1][$j] + $grid[$i][$j - 1] + $grid[$i][$j + 1]) % 2;
            }
        }
        for ($i = 0; $i < 10; $i++) {
            $grid[$i][0] = $grid[$i][9];
            $grid[$i][9] = $grid[$i][0];
            $grid[0][$i] = $grid[9][$i];
            $grid[9][$i] = $grid[0][$i];
        }
    }
}
cellular_automata();
?>