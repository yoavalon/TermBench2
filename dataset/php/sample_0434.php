<?php
function update_cell($state, $neighbors) {
    $active_neighbors = array_sum($neighbors);
    if ($state == 1) {
        return in_array($active_neighbors, [2, 3]) ? 1 : 0;
    } else {
        return $active_neighbors == 3 ? 1 : 0;
    }
}

function simulate($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = [];
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    if ($x == 0 && $y == 0) {
                        continue;
                    }
                    $ni = $i + $x;
                    $nj = $j + $y;
                    if ($ni >= 0 && $ni < $rows && $nj >= 0 && $nj < $cols) {
                        $neighbors[] = $grid[$ni][$nj];
                    }
                }
            }
            $new_grid[$i][$j] = update_cell($grid[$i][$j], $neighbors);
        }
    }
    return $new_grid;
}

function main() {
    $grid = [[0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]];
    while (true) {
        $grid = simulate($grid);
    }
}

main();
?>