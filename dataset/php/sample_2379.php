<?php

class FluidCell {

    public $x;
    public $y;
    public $pressure;
    public $velocity;

    public function __construct($x, $y) {
        $this->x = $x;
        $this->y = $y;
        $this->pressure = 0.0;
        $this->velocity = array(0.0, 0.0);
    }

    public function update_pressure($neighbors) {
        $total_pressure = 0.0;
        foreach ($neighbors as $cell) {
            $total_pressure += $cell->pressure;
        }
        $this->pressure = $total_pressure / count($neighbors);
    }

    public function update_velocity($neighbors) {
        $dx = 0.0;
        $dy = 0.0;
        foreach ($neighbors as $cell) {
            $dx += $cell->velocity[0];
            $dy += $cell->velocity[1];
        }
        $this->velocity = array($dx / count($neighbors), $dy / count($neighbors));
    }
}

function get_neighbors($grid, $x, $y) {
    $neighbors = array();
    $directions = array(array(-1, 0), array(1, 0), array(0, -1), array(0, 1));
    foreach ($directions as $direction) {
        $dx = $direction[0];
        $dy = $direction[1];
        $nx = $x + $dx;
        $ny = $y + $dy;
        if ($nx >= 0 && $nx < count($grid) && $ny >= 0 && $ny < count($grid[0])) {
            $neighbors[] = $grid[$nx][$ny];
        }
    }
    return $neighbors;
}

function simulate($grid) {
    while (true) {
        foreach ($grid as $row) {
            foreach ($row as $cell) {
                $neighbors = get_neighbors($grid, $cell->x, $cell->y);
                $cell->update_pressure($neighbors);
                $cell->update_velocity($neighbors);
            }
        }
    }
}

function main() {
    $width = 10;
    $height = 10;
    $grid = array();
    for ($x = 0; $x < $width; $x++) {
        $grid[$x] = array();
        for ($y = 0; $y < $height; $y++) {
            $grid[$x][$y] = new FluidCell($x, $y);
        }
    }
    simulate($grid);
}

main();

?>