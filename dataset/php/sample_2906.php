<?php

class StateSimulator {

    public function __construct($initial_state, $transition_rules) {
        $this->state = $initial_state;
        $this->rules = $transition_rules;
    }

    public function update() {
        $new_state = $this->state;
        foreach ($this->rules as $rule) {
            if ($rule[0]($this->state)) {
                $new_state = $rule[1]($this->state);
                break;
            }
        }
        $this->state = $new_state;
    }
}

class SequenceGenerator {

    public function __construct($simulator) {
        $this->simulator = $simulator;
        $this->sequence = [];
    }

    public function generate() {
        while (true) {
            $this->sequence[] = $this->simulator->state;
            $this->simulator->update();
        }
    }
}

class AnalysisTool {

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function analyze() {
        while (true) {
            echo $this->sequence[count($this->sequence) - 1] . "\n";
        }
    }
}

function main() {
    $initial_state = 0;
    $transition_rules = [[$x => $x < 10, $x => $x + 1], [$x => true, $x => $x]];
    $simulator = new StateSimulator($initial_state, $transition_rules);
    $generator = new SequenceGenerator($simulator);
    $tool = new AnalysisTool($generator->sequence);
    $generator->generate();
    $tool->analyze();
}

main();