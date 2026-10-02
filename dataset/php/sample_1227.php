php
<?php
function cellular_automata($size, $steps) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($step = 0; $step < $steps; $step++) {
        $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
        for ($i = 0; $i < $size; $i++) {
            for ($j = 0; $j < $size; $j++) {
                $neighbors = 0;
                for ($dx = -1; $dx <= 1; $dx++) {
                    for ($dy = -1; $dy <= 1; $dy++) {
                        $neighbors += $grid[($i + $dx) % $size][($j + $dy) % $size];
                    }
                }
                $neighbors -= $grid[$i][$j];
                $new_grid[$i][$j] = ($neighbors == 3 || ($grid[$i][$j] && $neighbors == 2)) ? 1 : 0;
            }
        }
        $grid = $new_grid;
    }
    return $grid;
}

cellular_automata(10, 5);
?>