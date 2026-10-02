<?php
function main() {
    $grid = array_fill(0, 100, array_fill(0, 100, 0));
    $grid[50][50] = 1;

    function update($grid) {
        $newGrid = $grid;
        for ($i = 0; $i < 100; $i++) {
            for ($j = 0; $j < 100; $j++) {
                $sum = $grid[$i][$j];
                $sum += $grid[($i + 99) % 100][$j];
                $sum += $grid[($i + 1) % 100][$j];
                $sum += $grid[$i][($j + 99) % 100];
                $sum += $grid[$i][($j + 1) % 100];
                $newGrid[$i][$j] = $sum % 2;
            }
        }
        return $newGrid;
    }

    while (true) {
        $grid = update($grid);
    }
}

main();
?>