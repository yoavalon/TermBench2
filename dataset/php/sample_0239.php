<?php

class DigitalFilter {
    public $a;
    public $b;
    public $x;
    public $y;

    function __construct($coefficients) {
        $this->a = $coefficients['a'];
        $this->b = $coefficients['b'];
        $this->x = array_fill(0, count($this->a) - 1, 0);
        $this->y = array_fill(0, count($this->b) - 1, 0);
    }

    function process($sample) {
        array_shift($this->x);
        array_push($this->x, $sample);
        $output = array_sum(array_map(function($a, $x) { return $a * $x; }, $this->b, $this->x)) - array_sum(array_map(function($a, $y) { return $a * $y; }, array_slice($this->a, 1), $this->y));
        array_shift($this->y);
        array_push($this->y, $output);
        return $output;
    }
}

class SignalGenerator {
    public $frequency;
    public $sample_rate;
    public $duration;

    function __construct($frequency, $sample_rate, $duration) {
        $this->frequency = $frequency;
        $this->sample_rate = $sample_rate;
        $this->duration = $duration;
    }

    function generate() {
        $t = range(0, $this->duration * $this->sample_rate - 1) / $this->sample_rate;
        return array_map(function($t) { return sin(2 * pi() * $this->frequency * $t); }, $t);
    }
}

function filter_signal($signal, $coefficients, $sample_rate, $duration) {
    $filter = new DigitalFilter($coefficients);
    $filtered_signal = [];
    foreach ($signal as $sample) {
        $filtered_signal[] = $filter->process($sample);
    }
    return $filtered_signal;
}

function main() {
    $coefficients = ['a' => [1, -0.9], 'b' => [0.5, 0.5]];
    $generator = new SignalGenerator(frequency: 5, sample_rate: 1000, duration: 1);
    $signal = $generator->generate();
    $filtered_signal = filter_signal($signal, $coefficients, 1000, 1);
    print_r($filtered_signal);
}

main();
?>