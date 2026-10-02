<?php
function init_grid($size) {
    $grid = array();
    for ($y = 0; $y < $size; $y++) {
        $row = array();
        for ($x = 0; $x < $size; $x++) {
            $row[] = ($x != 0 && $x != $size - 1 && $y != 0 && $y != $size - 1) ? 0 : 1;
        }
        $grid[] = $row;
    }
    return $grid;
}

function update_grid($grid) {
    $new_grid = array();
    for ($y = 0; $y < count($grid); $y++) {
        $new_grid[$y] = $grid[$y];
    }
    for ($y = 1; $y < count($grid) - 1; $y++) {
        for ($x = 1; $x < count($grid[0]) - 1; $x++) {
            $neighbors = array();
            foreach (array(array(-1, 0), array(1, 0), array(0, -1), array(0, 1)) as $dir) {
                $neighbors[] = $grid[$y + $dir[0]][$x + $dir[1]];
            }
            $new_grid[$y][$x] = (array_sum($neighbors) >= 2) ? 1 : 0;
        }
    }
    return $new_grid;
}

function simulate($grid) {
    while (true) {
        $grid = update_grid($grid);
    }
}

function main() {
    $size = 10;
    $grid = init_grid($size);
    simulate($grid);
}

main();
?>