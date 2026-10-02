<?php

class CellularAutomata {
    public $grid;

    function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
    }

    function update() {
        $new_grid = array_fill(0, count($this->grid), array_fill(0, count($this->grid), 0));
        for ($i = 0; $i < count($this->grid); $i++) {
            for ($j = 0; $j < count($this->grid); $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 0 && $neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                } elseif ($this->grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_grid[$i][$j] = 0;
                } else {
                    $new_grid[$i][$j] = $this->grid[$i][$j];
                }
            }
        }
        $this->grid = $new_grid;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min(count($this->grid), $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min(count($this->grid), $y + 2); $j++) {
                if (($i, $j) != ($x, $y) && $this->grid[$i][$j] == 1) {
                    $count++;
                }
            }
        }
        return $count;
    }
}

function main() {
    $size = 10;
    $ca = new CellularAutomata($size);
    $ca->grid[1][1] = 1;
    $ca->grid[2][2] = 1;
    $ca->grid[2][3] = 1;
    $ca->grid[3][1] = 1;
    $ca->grid[3][2] = 1;
    while (true) {
        $ca->update();
        foreach ($ca->grid as $row) {
            echo implode(' ', array_map('strval', $row));
            echo "\n";
        }
        echo "\n";
    }
}

main();

?>