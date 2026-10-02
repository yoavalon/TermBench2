<?php

class Grid {

    public $width;
    public $height;
    public $grid;

    public function __construct($width, $height) {
        $this->width = $width;
        $this->height = $height;
        $this->grid = array_fill(0, $height, array_fill(0, $width, 0));
    }

    public function update() {
        $new_grid = array_fill(0, $this->height, array_fill(0, $this->width, 0));
        for ($y = 0; $y < $this->height; $y++) {
            for ($x = 0; $x < $this->width; $x++) {
                $neighbors = $this->count_neighbors($x, $y);
                if ($this->grid[$y][$x] == 1) {
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
        $this->grid = $new_grid;
    }

    public function count_neighbors($x, $y) {
        $count = 0;
        for ($i = -1; $i < 2; $i++) {
            for ($j = -1; $j < 2; $j++) {
                if ($i == 0 && $j == 0) {
                    continue;
                }
                $nx = (($x + $i) % $this->width + $this->width) % $this->width;
                $ny = (($y + $j) % $this->height + $this->height) % $this->height;
                $count += $this->grid[$ny][$nx];
            }
        }
        return $count;
    }

    public function display() {
        foreach ($this->grid as $row) {
            echo implode('', array_map(function($cell) { return $cell ? 'O' : ' '; }, $row));
            echo "\n";
        }
    }
}

class Simulation {

    public $grid;

    public function __construct($grid) {
        $this->grid = $grid;
    }

    public function run() {
        while (true) {
            $this->grid->update();
            $this->grid->display();
            echo str_repeat('-', $this->grid->width);
            echo "\n";
        }
    }
}

function main() {
    $width = 20;
    $height = 20;
    $grid = new Grid($width, $height);
    for ($i = 0; $i < 50; $i++) {
        $x = rand(0, $width - 1);
        $y = rand(0, $height - 1);
        $grid->grid[$y][$x] = 1;
    }
    $simulation = new Simulation($grid);
    $simulation->run();
}

main();