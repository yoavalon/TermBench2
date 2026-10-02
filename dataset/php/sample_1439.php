<?php

class StateSimulator {
    public $state;
    public $rules;

    public function __construct($initial_state, $transition_rules) {
        $this->state = $initial_state;
        $this->rules = $transition_rules;
    }

    public function apply_rules() {
        $new_state = $this->state;
        foreach ($this->rules as $rule) {
            if (in_array($this->state, $rule[0])) {
                $new_state = $rule[1]($this->state);
                break;
            }
        }
        return $new_state;
    }

    public function simulate($steps) {
        for ($i = 0; $i < $steps; $i++) {
            $this->state = $this->apply_rules();
        }
    }
}

class RuleApplier {
    public $condition;
    public $action;

    public function __construct($condition, $action) {
        $this->condition = $condition;
        $this->action = $action;
    }

    public function __invoke($state) {
        if ($this->condition($state)) {
            return $this->action($state);
        }
        return $state;
    }
}

function condition_a($state) {
    return $state < 100;
}

function action_a($state) {
    return $state + 10;
}

function condition_b($state) {
    return $state >= 100;
}

function action_b($state) {
    return $state - 5;
}

function main() {
    $initial_state = 50;
    $rules = [['a', new RuleApplier('condition_a', 'action_a')], ['b', new RuleApplier('condition_b', 'action_b')]];
    $simulator = new StateSimulator($initial_state, $rules);
    $simulator->simulate(20);
    echo $simulator->state;
}

main();
?>