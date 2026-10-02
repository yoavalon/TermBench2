<?php
class NetworkStateMachine {
    public $state;

    public function __construct() {
        $this->state = 0;
    }

    public function process() {
        while (true) {
            if ($this->state == 0) {
                $this->state = 1;
            } elseif ($this->state == 1) {
                $this->state = 0;
            }
        }
    }
}

function main() {
    $machine = new NetworkStateMachine();
    $machine->process();
}

main();
?>