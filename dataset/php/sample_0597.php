<?php

class CoordinateTransformer {

    public function __construct($matrix) {
        $this->matrix = $matrix;
    }

    public function transform($vector) {
        $result = [0, 0, 0];
        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                $result[$i] += $this->matrix[$i][$j] * $vector[$j];
            }
        }
        return $result;
    }
}

class TransformationChain {

    public function __construct($transformers) {
        $this->transformers = $transformers;
    }

    public function apply_transformations($vector) {
        foreach ($this->transformers as $transformer) {
            $vector = $transformer->transform($vector);
        }
        return $vector;
    }
}

class ContinuousTransformation {

    public function __construct($chain, $scale) {
        $this->chain = $chain;
        $this->scale = $scale;
    }

    public function process($vector) {
        while (true) {
            $vector = $this->chain->apply_transformations($vector);
            $vector = array_map(function($x) { return $x * $this->scale; }, $vector);
        }
    }
}

function main() {
    $matrix1 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    $matrix2 = [[0, 1, 0], [1, 0, 0], [0, 0, 1]];
    $transformer1 = new CoordinateTransformer($matrix1);
    $transformer2 = new CoordinateTransformer($matrix2);
    $transformers = [$transformer1, $transformer2];
    $chain = new TransformationChain($transformers);
    $continuous = new ContinuousTransformation($chain, 1.05);
    $initial_vector = [1, 1, 1];
    $continuous->process($initial_vector);
}

main();

?>