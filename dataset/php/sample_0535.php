<?php

class Cell {
    public $state;

    function __construct($state) {
        $this->state = $state;
    }

    function update($neighbors) {
        $alive_neighbors = 0;
        foreach ($neighbors as $n) {
            if ($n->state == 1) {
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

class Grid {
    public $width;
    public $height;
    public $grid;

    function __construct($width, $height, $initial_state) {
        $this->width = $width;
        $this->height = $height;
        $this->grid = array();
        for ($x = 0; $x < $width; $x++) {
            for ($y = 0; $y < $height; $y++) {
                $this->grid[$x][$y] = new Cell($initial_state[$x][$y]);
            }
        }
    }

    function get_neighbors($x, $y) {
        $neighbors = array();
        for ($dx = -1; $dx <= 1; $dx++) {
            for ($dy = -1; $dy <= 1; $dy++) {
                if ($dx == 0 && $dy == 0) {
                    continue;
                }
                $nx = $x + $dx;
                $ny = $y + $dy;
                if ($nx >= 0 && $nx < $this->width && $ny >= 0 && $ny < $this->height) {
                    $neighbors[] = $this->grid[$nx][$ny];
                }
            }
        }
        return $neighbors;
    }

    function update() {
        $new_grid = array();
        for ($x = 0; $x < $this->width; $x++) {
            $new_grid[$x] = array();
            for ($y = 0; $y < $this->height; $y++) {
                $new_grid[$x][$y] = new Cell(0);
            }
        }
        for ($x = 0; $x < $this->width; $x++) {
            for ($y = 0; $y < $this->height; $y++) {
                $cell = $this->grid[$x][$y];
                $neighbors = $this->get_neighbors($x, $y);
                $new_grid[$x][$y]->update($neighbors);
            }
        }
        $this->grid = $new_grid;
    }
}

function main() {
    $width = 10;
    $height = 10;
    $initial_state = array(
        array(0, 1, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
        array(0, 1, 1, 1, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    );
    $grid = new Grid($width, $height, $initial_state);
    while (true) {
        $grid->update();
    }
}

main();
?>