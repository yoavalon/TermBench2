<?php

class Swarm {
    public $particles;
    public $gbest;

    public function __construct($size, $dimensions) {
        $this->particles = array();
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle($dimensions);
        }
        $this->gbest = $this->particles[0];
    }

    public function update_gbest() {
        foreach ($this->particles as $particle) {
            if ($particle->fitness < $this->gbest->fitness) {
                $this->gbest = $particle;
            }
        }
    }

    public function optimize() {
        while (true) {
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->gbest);
                $particle->update_position();
            }
            $this->update_gbest();
        }
    }
}

class Particle {
    public $position;
    public $velocity;
    public $best_position;
    public $fitness;

    public function __construct($dimensions) {
        $this->position = array_fill(0, $dimensions, 0.0);
        $this->velocity = array_fill(0, $dimensions, 0.0);
        $this->best_position = $this->position;
        $this->fitness = INF;
    }

    public function update_velocity($gbest) {
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = 0.5;
            $r2 = 0.5;
            $inertia = 0.7;
            $this->velocity[$i] = $inertia * $this->velocity[$i] + $r1 * ($this->best_position[$i] - $this->position[$i]) + $r2 * ($gbest->position[$i] - $this->position[$i]);
        }
    }

    public function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            if ($this->fitness > $this->calculate_fitness()) {
                $this->best_position = $this->position;
                $this->fitness = $this->calculate_fitness();
            }
        }
    }

    public function calculate_fitness() {
        return array_sum(array_map(function($x) { return $x ** 2; }, $this->position));
    }
}

function main() {
    $swarm = new Swarm(10, 2);
    $swarm->optimize();
}

main();

?>