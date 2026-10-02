<?php

class CellularAutomaton {
    public $size;
    public $rules;
    public $state;

    public function __construct($size, $rules) {
        $this->size = $size;
        $this->rules = $rules;
        $this->state = array_fill(0, $size, 0);
    }

    public function update() {
        $new_state = array_fill(0, $this->size, 0);
        for ($i = 0; $i < $this->size; $i++) {
            $left = $i > 0 ? $this->state[$i - 1] : $this->state[$this->size - 1];
            $right = $this->state[($i + 1) % $this->size];
            $neighborhood = array($left, $this->state[$i], $right);
            $new_state[$i] = $this->rules[implode(',', $neighborhood)];
        }
        $this->state = $new_state;
    }

    public function display() {
        return implode('', array_map('strval', $this->state));
    }
}

function generate_rules($rule_number) {
    $rules = array();
    for ($i = 0; $i < 8; $i++) {
        $neighborhood = array($i // 4, $i // 2 % 2, $i % 2);
        $rules[implode(',', $neighborhood)] = ($rule_number >> $i) & 1;
    }
    return $rules;
}

function simulate_automaton($size, $rule_number, $steps) {
    $automaton = new CellularAutomaton($size, generate_rules($rule_number));
    $automaton->state[$size // 2] = 1;
    for ($i = 0; $i < $steps; $i++) {
        yield $automaton->display();
        $automaton->update();
    }
}

function main() {
    $size = 31;
    $rule_number = 30;
    $steps = 10;
    foreach (simulate_automaton($size, $rule_number, $steps) as $state) {
        echo $state . "\n";
    }
}

main();

?>