<?php
function update_cell($grid, $i, $j, $size) {
    $neighbors = 0;
    for ($x = $i - 1; $x <= $i + 1; $x++) {
        for ($y = $j - 1; $y <= $j + 1; $y++) {
            if ($x >= 0 && $x < $size && $y >= 0 && $y < $size && ($x != $i || $y != $j)) {
                $neighbors += $grid[$x][$y];
            }
        }
    }
    return $neighbors == 3 || ($grid[$i][$j] && $neighbors == 2);
}

function step($grid) {
    $size = count($grid);
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $new_grid[$i][$j] = update_cell($grid, $i, $j, $size);
        }
    }
    return $new_grid;
}

function main() {
    $size = 10;
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    $grid[1][1] = 1;
    $grid[2][2] = 1;
    $grid[2][1] = 1;
    while (true) {
        $grid = step($grid);
    }
}

main();
?>