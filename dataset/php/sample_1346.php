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
            for ($x = $i - 1; $x <= $i + 1; $x++) {
                for ($y = $j - 1; $y <= $j + 1; $y++) {
                    if ($x >= 0 && $x < $size && $y >= 0 && $y < $size && ($x != $i || $y != $j)) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            if ($grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                $new_row[] = 0;
            } elseif ($grid[$i][$j] == 0 && $neighbors == 3) {
                $new_row[] = 1;
            } else {
                $new_row[] = $grid[$i][$j];
            }
        }
        $new_grid[] = $new_row;
    }
    return $new_grid;
}

function main() {
    $size = 5;
    $grid = initialize_grid($size);
    for ($i = 0; $i < 10; $i++) {
        $grid = update_grid($grid);
    }
    foreach ($grid as $row) {
        echo implode(' ', $row) . "\n";
    }
}

main();
?>