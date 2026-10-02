<?php
function init_grid($size) {
    $grid = [];
    for ($i = 0; $i < $size; $i++) {
        $row = [];
        for ($j = 0; $j < $size; $j++) {
            $row[] = rand(0, 1);
        }
        $grid[] = $row;
    }
    return $grid;
}

function update_grid($grid) {
    $new_grid = $grid;
    $size = count($grid);
    for ($i = 1; $i < $size - 1; $i++) {
        for ($j = 1; $j < $size - 1; $j++) {
            $neighbors = 0;
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    $neighbors += $grid[$i + $x][$j + $y];
                }
            }
            $neighbors -= $grid[$i][$j];
            if ($grid[$i][$j] && ($neighbors < 2 || $neighbors > 3)) {
                $new_grid[$i][$j] = 0;
            } elseif (!$grid[$i][$j] && $neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function main() {
    $size = 10;
    $grid = init_grid($size);
    while (true) {
        $grid = update_grid($grid);
        foreach ($grid as $row) {
            echo implode(' ', $row) . "\n";
        }
        echo str_repeat('-', 40) . "\n";
    }
}

main();
?>