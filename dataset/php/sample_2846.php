<?php
function generate_grid($size) {
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
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($dx = -1; $dx <= 1; $dx++) {
                for ($dy = -1; $dy <= 1; $dy++) {
                    if ($dx == 0 && $dy == 0) continue;
                    $neighbors += $grid[($i + $dx + $size) % $size][($j + $dy + $size) % $size];
                }
            }
            if (($grid[$i][$j] && ($neighbors == 2 || $neighbors == 3)) || (!$grid[$i][$j] && $neighbors == 3)) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function main() {
    $size = 10;
    $grid = generate_grid($size);
    while (true) {
        $grid = update_grid($grid);
    }
}

main();
?>