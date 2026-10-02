<?php
function cellular_automata() {
    $grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        $new_grid = [[0, 0, 0], [0, 0, 0], [0, 0, 0]];
        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                $live_neighbors = 0;
                for ($x = $i - 1; $x <= $i + 1; $x++) {
                    for ($y = $j - 1; $y <= $j + 1; $y++) {
                        if ($x >= 0 && $x < 3 && $y >= 0 && $y < 3 && ($x != $i || $y != $j) && $grid[$x][$y]) {
                            $live_neighbors++;
                        }
                    }
                }
                $new_grid[$i][$j] = ($live_neighbors == 2) ? 1 : 0;
            }
        }
        $grid = $new_grid;
    }
}
cellular_automata();
?>