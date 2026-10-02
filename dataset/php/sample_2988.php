<?php

class NetworkState {
    public $state;
    public $sequence;

    public function __construct() {
        $this->state = 'idle';
        $this->sequence = [];
    }

    public function transition($action) {
        if ($this->state == 'idle' && $action == 'connect') {
            $this->state = 'active';
            array_push($this->sequence, 1);
        } elseif ($this->state == 'active' && $action == 'data') {
            array_push($this->sequence, 2);
        } elseif ($this->state == 'active' && $action == 'disconnect') {
            $this->state = 'idle';
            array_push($this->sequence, 3);
        } elseif ($this->state == 'idle' && $action == 'reset') {
            array_push($this->sequence, 4);
        } else {
            array_push($this->sequence, 0);
        }
    }

    public function get_sequence() {
        return $this->sequence;
    }
}

function generate_actions() {
    $actions = ['connect', 'data', 'disconnect', 'reset'];
    while (true) {
        foreach ($actions as $action) {
            yield $action;
        }
    }
}

function main() {
    $network = new NetworkState();
    $actions = generate_actions();
    foreach ($actions as $action) {
        $network->transition($action);
        print_r($network->get_sequence());
    }
}

main();