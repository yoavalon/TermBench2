<?php

class Swarm {
    public $particles;
    public $best_position;

    public function __construct($size, $dimensions) {
        $this->particles = array();
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle($dimensions);
        }
        $this->best_position = null;
    }

    public function update_best_position() {
        if ($this->best_position === null) {
            $this->best_position = $this->particles[0]->position;
        } else {
            foreach ($this->particles as $particle) {
                if ($particle->fitness > $this->best_position->fitness) {
                    $this->best_position = $particle->position;
                }
            }
        }
    }

    public function update_particles($iterations) {
        if ($iterations > 0) {
            foreach ($this->particles as $particle) {
                $particle->update_velocity($this->best_position);
                $particle->update_position();
            }
            $this->update_best_position();
            $this->update_particles($iterations - 1);
        }
    }
}

class Particle {
    public $position;
    public $velocity;
    public $fitness;

    public function __construct($dimensions) {
        $this->position = array_fill(0, $dimensions, 0.0);
        $this->velocity = array_fill(0, $dimensions, 0.0);
        $this->fitness = 0.0;
    }

    public function update_velocity($best_position) {
        $w = 0.7;
        $c1 = 1.5;
        $c2 = 1.5;
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = 0.5;
            $r2 = 0.5;
            $cognitive = $c1 * $r1 * ($best_position[$i] - $this->position[$i]);
            $social = $c2 * $r2 * ($this->best_position[$i] - $this->position[$i]);
            $this->velocity[$i] = $w * $this->velocity[$i] + $cognitive + $social;
        }
    }

    public function update_position() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->fitness = $this->calculate_fitness();
        }
    }

    public function calculate_fitness() {
        $sum = 0.0;
        foreach ($this->position as $x) {
            $sum += pow($x, 2);
        }
        return $sum;
    }
}

function optimize($swarm, $iterations) {
    $swarm->update_particles($iterations);
}

function main() {
    $dimensions = 2;
    $swarm_size = 10;
    $iterations = 50;
    $swarm = new Swarm($swarm_size, $dimensions);
    optimize($swarm, $iterations);
}

main();

?>