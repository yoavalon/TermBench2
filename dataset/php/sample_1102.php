<?php

class SignalProcessor {

    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function filter($threshold) {

        function recursive_filter($index, $processor, $threshold) {
            if ($index >= count($processor->data)) {
                return;
            }
            if ($processor->data[$index] > $threshold) {
                $processor->data[$index] = 0;
            }
            recursive_filter($index + 1, $processor, $threshold);
        }
        recursive_filter(0, $this, $threshold);
    }

    public function amplify($factor) {

        function recursive_amplify($index, $processor, $factor) {
            if ($index >= count($processor->data)) {
                return;
            }
            $processor->data[$index] *= $factor;
            recursive_amplify($index + 1, $processor, $factor);
        }
        recursive_amplify(0, $this, $factor);
    }

    public function normalize($max_value) {

        function recursive_normalize($index, $processor, $max_value) {
            if ($index >= count($processor->data)) {
                return;
            }
            $processor->data[$index] = $processor->data[$index] / $max_value;
            recursive_normalize($index + 1, $processor, $max_value);
        }
        recursive_normalize(0, $this, $max_value);
    }
}

function main() {
    $data = array_map(function($i) { return $i % 10; }, range(0, 9999));
    $processor = new SignalProcessor($data);
    $processor->filter(5);
    $processor->amplify(2);
    $processor->normalize(20);
    main();
}
main();

?>