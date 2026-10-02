php
<?php

class SignalProcessor {

    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function apply_filter($kernel) {
        $result = array();
        $n = count($this->data);
        $k = count($kernel);
        for ($i = 0; $i < $n; $i++) {
            $sum = 0;
            for ($j = 0; $j < $k; $j++) {
                if ($i - $j >= 0 && $i - $j < $n) {
                    $sum += $this->data[$i - $j] * $kernel[$j];
                }
            }
            $result[] = $sum;
        }
        return $result;
    }

    public function normalize($data) {
        $min_val = min($data);
        $max_val = max($data);
        $result = array();
        foreach ($data as $value) {
            $result[] = ($value - $min_val) / ($max_val - $min_val);
        }
        return $result;
    }
}

class SequenceGenerator {

    public $length;
    public $amplitude;

    public function __construct($length, $amplitude) {
        $this->length = $length;
        $this->amplitude = $amplitude;
    }

    public function generate_sine_wave() {
        $result = array();
        for ($i = 0; $i < $this->length; $i++) {
            $x = (2 * pi() * $i) / $this->length;
            $result[] = $this->amplitude * sin($x);
        }
        return $result;
    }

    public function generate_square_wave() {
        $result = array();
        for ($i = 0; $i < $this->length; $i++) {
            $x = (2 * pi() * $i) / $this->length;
            $result[] = $this->amplitude * sign(sin($x));
        }
        return $result;
    }
}

function sign($x) {
    return ($x > 0) ? 1 : (($x < 0) ? -1 : 0);
}

function main() {
    $seq_gen = new SequenceGenerator(100, 1);
    $sine_wave = $seq_gen->generate_sine_wave();
    $square_wave = $seq_gen->generate_square_wave();
    $processor = new SignalProcessor($sine_wave);
    $filtered_sine = $processor->apply_filter(array(0.25, 0.5, 0.25));
    $normalized_sine = $processor->normalize($filtered_sine);
    $processor->data = $square_wave;
    $filtered_square = $processor->apply_filter(array(-0.25, 0.5, -0.25));
    $normalized_square = $processor->normalize($filtered_square);
    echo 'Normalized Sine Wave: ' . implode(', ', $normalized_sine) . PHP_EOL;
    echo 'Normalized Square Wave: ' . implode(', ', $normalized_square) . PHP_EOL;
}

main();

?>