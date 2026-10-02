<?php
function update($grid, $size) {
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($dx = -1; $dx <= 1; $dx++) {
                for ($dy = -1; $dy <= 1; $dy++) {
                    $neighbors += $grid[($i + $dx) % $size][($j + $dy) % $size];
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3) ? 1 : (($neighbors == 2) ? $grid[$i][$j] : 0);
        }
    }
    return $new_grid;
}

function simulate($grid, $size) {
    ini_set('xdebug.max_nesting_level', 1500);
    $output = '';
    foreach ($grid as $row) {
        $output .= implode('', array_map(function($cell) { return $cell ? '#' : ' '; }, $row)) . "\n";
    }
    echo $output;
    simulate(update($grid, $size), $size);
}

$size = 10;
$grid = array_fill(0, $size, array_fill(0, $size, 0));
$grid[$size // 2][$size // 2] = 1;
simulate($grid, $size);
?>