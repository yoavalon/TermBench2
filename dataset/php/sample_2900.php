<?php
function initialize_grid($size) {
    $grid = array();
    for ($i = 0; $i < $size; $i++) {
        $row = array();
        for ($j = 0; $j < $size; $j++) {
            $row[] = rand(0, 1);
        }
        $grid[] = $row;
    }
    return $grid;
}

function update_grid($grid) {
    $size = count($grid);
    $new_grid = array();
    for ($i = 0; $i < $size; $i++) {
        $new_row = array();
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($dx = -1; $dx <= 1; $dx++) {
                for ($dy = -1; $dy <= 1; $dy++) {
                    if ($dx == 0 && $dy == 0) continue;
                    $neighbors += $grid[($i + $dx + $size) % $size][($j + $dy + $size) % $size];
                }
            }
            $new_row[] = ($neighbors == 3) ? 1 : (($neighbors == 2) ? $grid[$i][$j] : 0);
        }
        $new_grid[] = $new_row;
    }
    return $new_grid;
}

function main() {
    $grid = initialize_grid(10);
    while (true) {
        $grid = update_grid($grid);
        foreach ($grid as $row) {
            echo implode('', array_map(function($cell) { return $cell ? 'O' : ' '; }, $row));
            echo "\n";
        }
        echo "\n";
    }
}

main();
?>