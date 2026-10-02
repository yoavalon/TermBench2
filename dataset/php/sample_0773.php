php
<?php
function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0;
            for ($ny = max(0, $y - 1); $ny < min($height, $y + 2); $ny++) {
                for ($nx = max(0, $x - 1); $nx < min($width, $x + 2); $nx++) {
                    $neighbors += $grid[$ny][$nx];
                }
            }
            $neighbors -= $grid[$y][$x];
            $new_grid[$y][$x] = ($neighbors == 3 || ($neighbors == 2 && $grid[$y][$x] == 1)) ? 1 : 0;
        }
    }
    return $new_grid;
}

function simulate($grid, $width, $height, $steps) {
    for ($i = 0; $i < $steps; $i++) {
        $grid = update_grid($grid, $width, $height);
    }
    return $grid;
}

function main() {
    $width = 10;
    $height = 10;
    $steps = 5;
    $initial_grid = array_fill(0, $height, array_fill(0, $width, 0));
    $initial_grid[5][5] = 1;
    $result = simulate($initial_grid, $width, $height, $steps);
    foreach ($result as $row) {
        echo implode('', array_map(function($cell) { return $cell ? 'O' : ' '; }, $row)) . "\n";
    }
}

main();
?>