<?php
class CellularAutomata {
    public $size;
    public $rule;
    public $grid;

    function __construct($size, $rule) {
        $this->size = $size;
        $this->rule = $rule;
        $this->grid = array_fill(0, $size, 0);
        $this->grid[floor($size / 2)] = 1;
    }

    function update() {
        $new_grid = array_fill(0, $this->size, 0);
        for ($i = 1; $i < $this->size - 1; $i++) {
            $pattern = array($this->grid[$i - 1], $this->grid[$i], $this->grid[$i + 1]);
            $new_grid[$i] = $this->rule[implode('', $pattern)];
        }
        $this->grid = $new_grid;
    }

    function run($steps) {
        for ($i = 0; $i < $steps; $i++) {
            $this->update();
        }
    }
}

function generate_rule($rule_number) {
    $rule = array();
    for ($i = 0; $i < 8; $i++) {
        $pattern = str_split(strrev(str_pad(decbin($i), 3, '0', STR_PAD_LEFT)));
        $rule[implode('', $pattern)] = ($rule_number >> $i) & 1;
    }
    return $rule;
}

function main() {
    $size = 51;
    $rule_number = 30;
    $steps = 10;
    $rule = generate_rule($rule_number);
    $ca = new CellularAutomata($size, $rule);
    $ca->run($steps);
    for ($row = 0; $row < $steps + 1; $row++) {
        echo str_repeat(' ', $size);
        for ($i = 0; $i < $size; $i++) {
            echo $ca->grid[$i] == 1 ? '#' : ' ';
        }
        echo "\n";
    }
}

main();