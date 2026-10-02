<?php

class Automaton {
    public $size;
    public $rule;
    public $state;

    function __construct($size, $rule) {
        $this->size = $size;
        $this->rule = $rule;
        $this->state = array_fill(0, $size, 0);
        $this->state[$size // 2] = 1;
    }

    function evolve() {
        $new_state = array_fill(0, $this->size, 0);
        for ($i = 1; $i < $this->size - 1; $i++) {
            $pattern = array($this->state[$i - 1], $this->state[$i], $this->state[$i + 1]);
            $new_state[$i] = $this->rule[implode(',', $pattern)];
        }
        $this->state = $new_state;
    }

    function display() {
        return implode('', array_map('strval', $this->state));
    }
}

function generate_rule($number) {
    $rule = array();
    for ($i = 0; $i < 8; $i++) {
        $pattern = array($i // 4, $i // 2 % 2, $i % 2);
        $rule[implode(',', $pattern)] = ($number >> $i) & 1;
    }
    return $rule;
}

function main() {
    $size = 31;
    $rule_number = 30;
    $rule = generate_rule($rule_number);
    $automaton = new Automaton($size, $rule);
    $iterations = 10;
    for ($i = 0; $i < $iterations; $i++) {
        echo $automaton->display() . "\n";
        $automaton->evolve();
    }
}

main();

?>