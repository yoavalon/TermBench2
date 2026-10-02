<?php

class AutomatonCell {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function update_state($neighbors) {
        $alive_neighbors = 0;
        foreach ($neighbors as $cell) {
            if ($cell->state == 1) {
                $alive_neighbors++;
            }
        }
        if ($this->state == 1) {
            if ($alive_neighbors < 2 || $alive_neighbors > 3) {
                $this->state = 0;
            }
        } elseif ($alive_neighbors == 3) {
            $this->state = 1;
        }
    }
}

class AutomatonGrid {
    public $grid;

    public function __construct($size) {
        $this->grid = [];
        for ($i = 0; $i < $size; $i++) {
            $row = [];
            for ($j = 0; $j < $size; $j++) {
                $row[] = new AutomatonCell(rand(0, 1));
            }
            $this->grid[] = $row;
        }
    }

    public function get_neighbors($x, $y) {
        $size = count($this->grid);
        $neighbors = [];
        for ($i = -1; $i <= 1; $i++) {
            for ($j = -1; $j <= 1; $j++) {
                if ($i == 0 && $j == 0) {
                    continue;
                }
                $nx = $x + $i;
                $ny = $y + $j;
                if ($nx >= 0 && $nx < $size && $ny >= 0 && $ny < $size) {
                    $neighbors[] = $this->grid[$nx][$ny];
                }
            }
        }
        return $neighbors;
    }

    public function update_grid() {
        $size = count($this->grid);
        $new_grid = [];
        for ($i = 0; $i < $size; $i++) {
            $row = [];
            for ($j = 0; $j < $size; $j++) {
                $neighbors = $this->get_neighbors($i, $j);
                $new_cell = new AutomatonCell(0);
                $new_cell->update_state($neighbors);
                $row[] = $new_cell;
            }
            $new_grid[] = $row;
        }
        $this->grid = $new_grid;
    }
}

function simulate() {
    $size = 50;
    $grid = new AutomatonGrid($size);
    while (true) {
        $grid->update_grid();
    }
}

simulate();

?>