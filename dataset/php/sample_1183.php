php
<?php

class Swarm {
    public $size;
    public $dimensions;
    public $positions;
    public $velocities;
    public $best_positions;
    public $best_scores;
    public $global_best_position;
    public $global_best_score;

    public function __construct($size, $dimensions) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->positions = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->velocities = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->best_positions = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->best_scores = array_fill(0, $size, INF);
        $this->global_best_position = array_fill(0, $dimensions, 0.0);
        $this->global_best_score = INF;
    }

    public function update_global_best() {
        for ($i = 0; $i < $this->size; $i++) {
            $score = $this->evaluate($this->best_positions[$i]);
            if ($score < $this->global_best_score) {
                $this->global_best_score = $score;
                $this->global_best_position = $this->best_positions[$i];
            }
        }
    }

    public function evaluate($position) {
        return array_sum(array_map(function($x) { return $x ** 2; }, $position));
    }

    public function update_particles() {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $r1 = 0.5;
                $r2 = 0.5;
                $c1 = 2.0;
                $c2 = 2.0;
                $this->velocities[$i][$j] = 0.7 * $this->velocities[$i][$j] + $c1 * $r1 * ($this->best_positions[$i][$j] - $this->positions[$i][$j]) + $c2 * $r2 * ($this->global_best_position[$j] - $this->positions[$i][$j]);
                $this->positions[$i][$j] += $this->velocities[$i][$j];
            }
            $this->best_scores[$i] = $this->evaluate($this->positions[$i]);
            if ($this->best_scores[$i] < $this->global_best_score) {
                $this->best_positions[$i] = $this->positions[$i];
            }
        }
    }

    public function iterate() {
        $this->update_global_best();
        $this->update_particles();
        $this->iterate();
    }
}

function main() {
    $swarm = new Swarm(30, 2);
    $swarm->iterate();
}

main();

?>