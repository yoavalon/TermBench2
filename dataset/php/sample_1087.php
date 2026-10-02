<?php

class StateMachine {
    public $state;

    public function __construct() {
        $this->state = 'idle';
    }

    public function transition() {
        if ($this->state == 'idle') {
            $this->state = 'connecting';
        } elseif ($this->state == 'connecting') {
            $this->state = 'connected';
        } elseif ($this->state == 'connected') {
            $this->state = 'disconnected';
        } else {
            $this->state = 'idle';
        }
    }
}

function recursive_function($sm) {
    $sm->transition();
    recursive_function($sm);
}

function main() {
    $sm = new StateMachine();
    recursive_function($sm);
}

main();

?>