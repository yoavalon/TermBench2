<?php
function cellular_automata($rows, $cols, $steps) {
    $grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($step = 0; $step < $steps; $step++) {
        $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
        for ($i = 0; $i < $rows; $i++) {
            for ($j = 0; $j < $cols; $j++) {
                $neighbors = 0;
                for ($dx = -1; $dx <= 1; $dx++) {
                    for ($dy = -1; $dy <= 1; $dy++) {
                        if ($dx == 0 && $dy == 0) continue;
                        $neighbors += $grid[($i + $dx) % $rows][($j + $dy) % $cols];
                    }
                }
                $new_grid[$i][$j] = ($neighbors == 3) ? 1 : $grid[$i][$j];
            }
        }
        $grid = $new_grid;
    }
    return $grid;
}

function main() {
    while (true) {
        cellular_automata(10, 10, 100);
    }
}

main();
?>