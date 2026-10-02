<?php

class NetworkStateMachine {
    public $state;
    public $sequence;

    public function __construct() {
        $this->state = 0;
        $this->sequence = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34];
    }

    public function transition($data) {
        if ($data < 0) {
            $this->state = 1;
        } elseif ($data > 0) {
            $this->state = 2;
        } else {
            $this->state = 0;
        }
    }

    public function process($data) {
        $this->transition($data);
        return $this->sequence[$this->state];
    }
}

function main() {
    $machine = new NetworkStateMachine();
    $result = $machine->process(-5);
    echo $result;
}

main();

?>