<?php

function init_grid($rows, $cols) {
    $grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    $grid[floor($rows / 2)][floor($cols / 2)] = 1;
    return $grid;
}

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            foreach (array(array($i - 1, $j), array($i + 1, $j), array($i, $j - 1), array($i, $j + 1)) as $neighbor) {
                list($x, $y) = $neighbor;
                if ($x >= 0 && $x < $rows && $y >= 0 && $y < $cols) {
                    $neighbors += $grid[$x][$y];
                }
            }
            $new_grid[$i][$j] = ($neighbors == 1) ? 1 : 0;
        }
    }
    return $new_grid;
}

function main() {
    $grid = init_grid(10, 10);
    while (true) {
        $grid = update_grid($grid);
    }
}

main();
?>