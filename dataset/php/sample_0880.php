<?php
function update_state($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0;
            for ($dy = -1; $dy < 2; $dy++) {
                for ($dx = -1; $dx < 2; $dx++) {
                    if ($dy == 0 && $dx == 0) continue;
                    $nx = $x + $dx;
                    $ny = $y + $dy;
                    if ($nx >= 0 && $nx < $width && $ny >= 0 && $ny < $height) {
                        $neighbors += $grid[$ny][$nx];
                    }
                }
            }
            if ($grid[$y][$x] == 1) {
                if ($neighbors < 2 || $neighbors > 3) {
                    $new_grid[$y][$x] = 0;
                } else {
                    $new_grid[$y][$x] = 1;
                }
            } elseif ($neighbors == 3) {
                $new_grid[$y][$x] = 1;
            }
        }
    }
    return $new_grid;
}

function run_simulation($grid, $width, $height, $steps) {
    if ($steps == 0) {
        return $grid;
    } else {
        $grid = update_state($grid, $width, $height);
        return run_simulation($grid, $width, $height, $steps - 1);
    }
}

function main() {
    $width = 10;
    $height = 10;
    $initial_grid = array(
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 1, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 1, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    );
    $steps = 10;
    $final_grid = run_simulation($initial_grid, $width, $height, $steps);
    foreach ($final_grid as $row) {
        echo implode(" ", $row) . "\n";
    }
}

main();
?>