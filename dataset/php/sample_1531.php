<?php
function cellular_automata($width, $height) {
    $grid = array_fill(0, $height, array_fill(0, $width, 0));
    while (true) {
        $new_grid = $grid;
        for ($i = 1; $i < $height - 1; $i++) {
            for ($j = 1; $j < $width - 1; $j++) {
                $neighbors = 0;
                for ($ni = $i - 1; $ni <= $i + 1; $ni++) {
                    for ($nj = $j - 1; $nj <= $j + 1; $nj++) {
                        $neighbors += $grid[$ni][$nj];
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
        $grid = $new_grid;
    }
}
cellular_automata(50, 50);
?>