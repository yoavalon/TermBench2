<?php

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($rows, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($cols, $j + 2); $y++) {
                    $neighbors += $grid[$x][$y];
                }
            }
            $neighbors -= $grid[$i][$j];
            if ($grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                $new_grid[$i][$j] = 0;
            } elseif ($grid[$i][$j] == 0 && $neighbors == 3) {
                $new_grid[$i][$j] = 1;
            } else {
                $new_grid[$i][$j] = $grid[$i][$j];
            }
        }
    }
    return $new_grid;
}

function simulate() {
    $grid_size = 50;
    $grid = array();
    for ($i = 0; $i < $grid_size; $i++) {
        $grid[$i] = array_fill(0, $grid_size, rand(0, 1));
    }
    while (true) {
        $grid = update_grid($grid);
        yield $grid;
    }
}

function main() {
    $sim = simulate();
    for ($i = 0; $i < 1000; $i++) {
        $grid = $sim->current();
        print_r($grid);
        $sim->next();
    }
}

main();

?>