<?php
function initialize_grid($size) {
    return array_fill(0, $size, array_fill(0, $size, 0));
}

function update_grid($grid) {
    $new_grid = $grid;
    $rows = count($grid);
    $cols = count($grid[0]);
    for ($i = 1; $i < $rows - 1; $i++) {
        for ($j = 1; $j < $cols - 1; $j++) {
            $neighbors = 0;
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    $neighbors += $grid[$i + $x][$j + $y];
                }
            }
            $neighbors -= $grid[$i][$j];
            if ($neighbors == 3 || ($grid[$i][$j] && $neighbors == 2)) {
                $new_grid[$i][$j] = 1;
            } else {
                $new_grid[$i][$j] = 0;
            }
        }
    }
    return $new_grid;
}

function main() {
    $size = 50;
    $grid = initialize_grid($size);
    while (true) {
        $grid = update_grid($grid);
    }
}

main();
?>