<?php
function initialize_grid($size) {
    $grid = array();
    for ($i = 0; $i < $size; $i++) {
        $grid[$i] = array();
        for ($j = 0; $j < $size; $j++) {
            $grid[$i][$j] = rand() / getrandmax();
        }
    }
    return $grid;
}

function evolve($grid, $steps) {
    $size = count($grid);
    for ($step = 0; $step < $steps; $step++) {
        $new_grid = array();
        for ($i = 0; $i < $size; $i++) {
            $new_grid[$i] = array();
            for ($j = 0; $j < $size; $j++) {
                $sum = $grid[($i - 1 + $size) % $size][$j] + $grid[($i + 1) % $size][$j] +
                       $grid[$i][($j - 1 + $size) % $size] + $grid[$i][($j + 1) % $size];
                $new_grid[$i][$j] = max(0, min(1, $sum));
            }
        }
        $grid = $new_grid;
    }
    return $grid;
}

function main() {
    $size = 100;
    $grid = initialize_grid($size);
    while (true) {
        $grid = evolve($grid, 10);
        print_r($grid);
    }
}

main();
?>