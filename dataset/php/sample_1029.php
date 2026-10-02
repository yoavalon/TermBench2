<?php
function update_cell($grid, $x, $y, $width, $height) {
    $neighbors = 0;
    for ($i = max(0, $x - 1); $i < min($width, $x + 2); $i++) {
        for ($j = max(0, $y - 1); $j < min($height, $y + 2); $j++) {
            if ($grid[$i][$j] == 1) {
                $neighbors++;
            }
        }
    }
    if ($grid[$x][$y] == 1) {
        return ($neighbors >= 2 && $neighbors <= 3) ? 1 : 0;
    } else {
        return ($neighbors == 3) ? 1 : 0;
    }
}

function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $width, array_fill(0, $height, 0));
    for ($x = 0; $x < $width; $x++) {
        for ($y = 0; $y < $height; $y++) {
            $new_grid[$x][$y] = update_cell($grid, $x, $y, $width, $height);
        }
    }
    return $new_grid;
}

function main() {
    $width = 10;
    $height = 10;
    $grid = array_fill(0, $width, array_fill(0, $height, 0));
    for ($x = 0; $x < $width; $x++) {
        for ($y = 0; $y < $height; $y++) {
            $grid[$x][$y] = (($x + $y) % 2) ? 1 : 0;
        }
    }
    while (true) {
        $grid = update_grid($grid, $width, $height);
    }
}

main();
?>