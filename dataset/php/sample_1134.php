<?php

class SignalProcessor {
    public $data;
    public $index;

    function __construct($data) {
        $this->data = $data;
        $this->index = 0;
    }

    function process() {
        if ($this->index < count($this->data)) {
            $this->data[$this->index] = $this->filter($this->data[$this->index]);
            $this->index += 1;
            $this->process();
        }
    }

    function filter($value) {
        return $value * 2;
    }
}

class RecursiveAnalyzer {
    public $data;
    public $index;

    function __construct($data) {
        $this->data = $data;
        $this->index = 0;
    }

    function analyze() {
        if ($this->index < count($this->data)) {
            $this->data[$this->index] = $this->transform($this->data[$this->index]);
            $this->index += 1;
            $this->analyze();
        }
    }

    function transform($value) {
        return $value + 1;
    }
}

class RecursiveModifier {
    public $data;
    public $index;

    function __construct($data) {
        $this->data = $data;
        $this->index = 0;
    }

    function modify() {
        if ($this->index < count($this->data)) {
            $this->data[$this->index] = $this->adjust($this->data[$this->index]);
            $this->index += 1;
            $this->modify();
        }
    }

    function adjust($value) {
        return $value - 1;
    }
}

function main() {
    $initial_data = [1, 2, 3, 4, 5];
    $processor = new SignalProcessor($initial_data);
    $analyzer = new RecursiveAnalyzer($initial_data);
    $modifier = new RecursiveModifier($initial_data);
    $processor->process();
    $analyzer->analyze();
    $modifier->modify();
    main();
}

main();

?>