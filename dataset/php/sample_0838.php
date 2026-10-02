<?php

class Swarm {
    public $size;
    public $dimensions;
    public $bounds;
    public $positions;
    public $velocities;
    public $pbest_positions;
    public $pbest_scores;
    public $gbest_position;
    public $gbest_score;

    function __construct($size, $dimensions, $bounds) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->bounds = $bounds;
        $this->positions = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->velocities = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->pbest_positions = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->pbest_scores = array_fill(0, $size, INF);
        $this->gbest_position = array_fill(0, $dimensions, 0.0);
        $this->gbest_score = INF;
    }

    function initialize() {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $this->positions[$i][$j] = ($this->bounds[$j][1] - $this->bounds[$j][0]) * rand() / getrandmax() + $this->bounds[$j][0];
                $this->velocities[$i][$j] = ($this->bounds[$j][1] - $this->bounds[$j][0]) * rand() / getrandmax() - ($this->bounds[$j][1] - $this->bounds[$j][0]) / 2;
            }
        }
    }

    function evaluate($function) {
        for ($i = 0; $i < $this->size; $i++) {
            $score = $function($this->positions[$i]);
            if ($score < $this->pbest_scores[$i]) {
                $this->pbest_scores[$i] = $score;
                $this->pbest_positions[$i] = $this->positions[$i];
            }
            if ($score < $this->gbest_score) {
                $this->gbest_score = $score;
                $this->gbest_position = $this->positions[$i];
            }
        }
    }

    function update_velocities($w, $c1, $c2) {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $this->velocities[$i][$j] = $w * $this->velocities[$i][$j] + $c1 * rand() / getrandmax() * ($this->pbest_positions[$i][$j] - $this->positions[$i][$j]) + $c2 * rand() / getrandmax() * ($this->gbest_position[$j] - $this->positions[$i][$j]);
            }
        }
    }

    function update_positions() {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $this->positions[$i][$j] += $this->velocities[$i][$j];
                $this->positions[$i][$j] = max($this->bounds[$j][0], min($this->bounds[$j][1], $this->positions[$i][$j]));
            }
        }
    }

    function optimize($function, $iterations) {
        $this->initialize();
        for ($k = 0; $k < $iterations; $k++) {
            $this->evaluate($function);
            $this->update_velocities(0.7, 1.5, 1.5);
            $this->update_positions();
        }
        return $this->gbest_score;
    }
}

function objective($x) {
    $sum = 0;
    foreach ($x as $xi) {
        $sum += pow($xi - 0.5, 2);
    }
    return $sum;
}

function main() {
    $dimensions = 3;
    $bounds = array_fill(0, $dimensions, array(-10, 10));
    $swarm_size = 30;
    $iterations = 100;
    $swarm = new Swarm($swarm_size, $dimensions, $bounds);
    $best_score = $swarm->optimize("objective", $iterations);
    echo $best_score;
}

main();

?>