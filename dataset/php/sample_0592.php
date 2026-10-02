<?php

class Swarm {
    public $size;
    public $dimensions;
    public $particles;
    public $velocities;
    public $best_positions;
    public $best_scores;
    public $global_best;
    public $global_best_score;

    function __construct($size, $dimensions) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->particles = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->velocities = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->best_positions = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->best_scores = array_fill(0, $size, INF);
        $this->global_best = array_fill(0, $dimensions, 0.0);
        $this->global_best_score = INF;
    }

    function update_global_best() {
        for ($i = 0; $i < $this->size; $i++) {
            if ($this->best_scores[$i] < $this->global_best_score) {
                $this->global_best_score = $this->best_scores[$i];
                $this->global_best = $this->best_positions[$i];
            }
        }
    }

    function update_particles() {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $r1 = 0.5;
                $r2 = 0.5;
                $cognitive = $r1 * ($this->best_positions[$i][$j] - $this->particles[$i][$j]);
                $social = $r2 * ($this->global_best[$j] - $this->particles[$i][$j]);
                $this->velocities[$i][$j] += $cognitive + $social;
                $this->particles[$i][$j] += $this->velocities[$i][$j];
            }
        }
    }

    function evaluate($objective_function) {
        for ($i = 0; $i < $this->size; $i++) {
            $score = $objective_function($this->particles[$i]);
            if ($score < $this->best_scores[$i]) {
                $this->best_scores[$i] = $score;
                $this->best_positions[$i] = $this->particles[$i];
            }
        }
        $this->update_global_best();
    }
}

class Optimization {
    public $swarm;
    public $objective_function;

    function __construct($swarm, $objective_function) {
        $this->swarm = $swarm;
        $this->objective_function = $objective_function;
    }

    function run() {
        while (true) {
            $this->swarm->update_particles();
            $this->swarm->evaluate($this->objective_function);
        }
    }
}

function objective_function($position) {
    return array_sum(array_map(function($x) { return $x ** 2; }, $position));
}

function main() {
    $size = 30;
    $dimensions = 2;
    $swarm = new Swarm($size, $dimensions);
    $optimization = new Optimization($swarm, 'objective_function');
    $optimization->run();
}

main();