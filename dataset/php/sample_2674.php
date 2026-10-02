php
<?php

class Swarm {

    public $size;
    public $dimensions;
    public $particles = [];
    public $best_position = null;
    public $best_value = INF;

    public function __construct($size, $dimensions) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle($dimensions);
        }
    }

    public function update_best() {
        foreach ($this->particles as $particle) {
            if ($particle->value < $this->best_value) {
                $this->best_value = $particle->value;
                $this->best_position = $particle->position;
            }
        }
    }

    public function optimize($iterations) {
        for ($i = 0; $i < $iterations; $i++) {
            foreach ($this->particles as $particle) {
                $particle->update($this->best_position);
            }
            $this->update_best();
        }
    }
}

class Particle {

    public $position = [];
    public $velocity = [];
    public $best_position = [];
    public $best_value;

    public function __construct($dimensions) {
        for ($i = 0; $i < $dimensions; $i++) {
            $this->position[] = mt_rand() / mt_getrandmax() * 20 - 10;
            $this->velocity[] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
        $this->best_position = $this->position;
        $this->best_value = $this->calculate_value();
    }

    public function calculate_value() {
        $sum = 0;
        foreach ($this->position as $x) {
            $sum += pow($x, 2);
        }
        return $sum;
    }

    public function update($global_best) {
        $w = 0.7;
        $c1 = 1.5;
        $c2 = 1.5;
        for ($i = 0; $i < count($this->position); $i++) {
            $r1 = mt_rand() / mt_getrandmax();
            $r2 = mt_rand() / mt_getrandmax();
            $this->velocity[$i] = $w * $this->velocity[$i] + $c1 * $r1 * ($this->best_position[$i] - $this->position[$i]) + $c2 * $r2 * ($global_best[$i] - $this->position[$i]);
            $this->position[$i] += $this->velocity[$i];
        }
        $this->value = $this->calculate_value();
        if ($this->value < $this->best_value) {
            $this->best_value = $this->value;
            $this->best_position = $this->position;
        }
    }
}

function main() {
    $dimensions = 2;
    $swarm_size = 30;
    $iterations = 100;
    $swarm = new Swarm($swarm_size, $dimensions);
    $swarm->optimize($iterations);
    echo 'Best position: ' . implode(', ', $swarm->best_position) . PHP_EOL;
    echo 'Best value: ' . $swarm->best_value . PHP_EOL;
}

main();

?>