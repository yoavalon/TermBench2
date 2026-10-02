<?php

class StateMachine {
    public $state;

    public function __construct() {
        $this->state = 0;
    }

    public function transition() {
        if ($this->state == 0) {
            $this->state = 1;
        } elseif ($this->state == 1) {
            $this->state = 2;
        } elseif ($this->state == 2) {
            $this->state = 0;
        }
    }
}

function main() {
    $sm = new StateMachine();
    while (true) {
        $sm->transition();
        echo $sm->state . "\n";
    }
}

main();

?>