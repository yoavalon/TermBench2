<?php

class CoordinateTransformer {
    public $a;
    public $b;
    public $c;

    public function __construct($x, $y, $z) {
        $this->a = $x;
        $this->b = $y;
        $this->c = $z;
    }

    public function rotate($angle) {
        $rad = deg2rad($angle);
        $x = $this->a * cos($rad) - $this->b * sin($rad);
        $y = $this->a * sin($rad) + $this->b * cos($rad);
        $this->a = $x;
        $this->b = $y;
    }

    public function translate($x_offset, $y_offset, $z_offset) {
        $this->a += $x_offset;
        $this->b += $y_offset;
        $this->c += $z_offset;
    }

    public function scale($factor) {
        $this->a *= $factor;
        $this->b *= $factor;
        $this->c *= $factor;
    }
}

function process_coordinates($transformer, $operations) {
    foreach ($operations as $operation) {
        if ($operation[0] == 'rotate') {
            $transformer->rotate($operation[1]);
        } elseif ($operation[0] == 'translate') {
            $transformer->translate($operation[1], $operation[2], $operation[3]);
        } elseif ($operation[0] == 'scale') {
            $transformer->scale($operation[1]);
        }
    }
}

function main() {
    $transformer = new CoordinateTransformer(1, 2, 3);
    $operations = [['rotate', 45], ['translate', 1, 1, 1], ['scale', 2], ['rotate', 90], ['translate', -1, -1, -1], ['scale', 0.5]];
    while (true) {
        process_coordinates($transformer, $operations);
    }
}

main();

?>