<?php

class Grid {

    public $size;
    public $grid;

    function __construct($size) {
        $this->size = $size;
        $this->grid = array();
        for ($i = 0; $i < $size; $i++) {
            $this->grid[$i] = array();
            for ($j = 0; $j < $size; $j++) {
                $this->grid[$i][$j] = rand(0, 1);
            }
        }
    }

    function update() {
        $new_grid = array();
        for ($i = 0; $i < $this->size; $i++) {
            $new_grid[$i] = array();
            for ($j = 0; $j < $this->size; $j++) {
                $state = $this->grid[$i][$j];
                $neighbors = $this->count_neighbors($i, $j);
                if ($state == 0 && $neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                } elseif ($state == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_grid[$i][$j] = 0;
                } else {
                    $new_grid[$i][$j] = $state;
                }
            }
        }
        $this->grid = $new_grid;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($x + 2, $this->size); $i++) {
            for ($j = max(0, $y - 1); $j < min($y + 2, $this->size); $j++) {
                if ($i != $x || $j != $y) {
                    $count += $this->grid[$i][$j];
                }
            }
        }
        return $count;
    }
}

class Simulation {

    public $grid;

    function __construct($grid) {
        $this->grid = $grid;
    }

    function run() {
        while (true) {
            $this->grid->update();
            $this->display();
        }
    }

    function display() {
        foreach ($this->grid->grid as $row) {
            $output = '';
            foreach ($row as $cell) {
                $output .= ($cell ? '#' : ' ');
            }
            echo $output . "\n";
        }
        echo str_repeat('-', $this->grid->size) . "\n";
    }
}

function main() {
    $size = 50;
    $grid = new Grid($size);
    $simulation = new Simulation($grid);
    $simulation->run();
}

main();

?>