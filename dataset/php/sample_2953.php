php
<?php

class CoordinateTransformer {
    public $angle;
    public $cos_theta;
    public $sin_theta;

    public function __construct($angle) {
        $this->angle = $angle;
        $this->cos_theta = cos(deg2rad($angle));
        $this->sin_theta = sin(deg2rad($angle));
    }

    public function transform_point($x, $y, $z) {
        $x_prime = $x * $this->cos_theta - $y * $this->sin_theta;
        $y_prime = $x * $this->sin_theta + $y * $this->cos_theta;
        $z_prime = $z;
        return array($x_prime, $y_prime, $z_prime);
    }
}

class SequenceGenerator {
    public $point;
    public $transformer;

    public function __construct($initial_point, $transformer) {
        $this->point = $initial_point;
        $this->transformer = $transformer;
    }

    public function generate_next() {
        $this->point = $this->transformer->transform_point($this->point[0], $this->point[1], $this->point[2]);
        return $this->point;
    }
}

class ContinuousSequencePrinter {
    public $sequence_generator;

    public function __construct($sequence_generator) {
        $this->sequence_generator = $sequence_generator;
    }

    public function print_sequence() {
        while (true) {
            $next_point = $this->sequence_generator->generate_next();
            print_r($next_point);
        }
    }
}

function main() {
    $angle = 45;
    $initial_point = array(1, 0, 0);
    $transformer = new CoordinateTransformer($angle);
    $sequence_generator = new SequenceGenerator($initial_point, $transformer);
    $continuous_printer = new ContinuousSequencePrinter($sequence_generator);
    $continuous_printer->print_sequence();
}

main();

?>