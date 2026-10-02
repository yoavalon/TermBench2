php
<?php

class CellularAutomata {
    public $grid;
    public $size;

    public function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
    }

    public function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 1) {
                    if ($neighbors < 2 || $neighbors > 3) {
                        $new_grid[$i][$j] = 0;
                    } else {
                        $new_grid[$i][$j] = 1;
                    }
                } elseif ($neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                }
            }
        }
        $this->grid = $new_grid;
    }

    public function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($x + 2, $this->size); $i++) {
            for ($j = max(0, $y - 1); $j < min($y + 2, $this->size); $j++) {
                if (($i, $j) != ($x, $y) && $this->grid[$i][$j] == 1) {
                    $count += 1;
                }
            }
        }
        return $count;
    }
}

function main() {
    $ca = new CellularAutomata(10);
    $ca->grid[5][5] = 1;
    $ca->grid[5][6] = 1;
    $ca->grid[6][5] = 1;
    $ca->grid[6][6] = 1;
    while (true) {
        $ca->update();
    }
}

main();
?>