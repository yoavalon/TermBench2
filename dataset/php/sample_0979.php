<?php
function fluid_dynamics($grid) {
    $size = count($grid);
    $next_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($size, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($size, $j + 2); $y++) {
                    $neighbors += $grid[$x][$y];
                }
            }
            $next_grid[$i][$j] = ($neighbors > 4) ? 1 : 0;
        }
    }
    return fluid_dynamics($next_grid);
}

$grid = array_fill(0, 10, array_fill(0, 10, 0));
$grid[5][5] = 1;
fluid_dynamics($grid);
?>