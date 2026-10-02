<?php

class ConnectionState {
    public $state;

    function __construct() {
        $this->state = 'CLOSED';
    }

    function transition($event) {
        if ($this->state == 'CLOSED' && $event == 'OPEN') {
            $this->state = 'OPEN';
        } elseif ($this->state == 'OPEN' && $event == 'DATA') {
            $this->state = 'DATA';
        } elseif ($this->state == 'DATA' && $event == 'CLOSE') {
            $this->state = 'CLOSED';
        }
    }
}

function simulate_network() {
    $conn = new ConnectionState();
    $events = ['OPEN', 'DATA', 'CLOSE', 'OPEN', 'DATA', 'DATA', 'CLOSE'];
    foreach ($events as $event) {
        $conn->transition($event);
        echo $conn->state . "\n";
    }
}

function main() {
    while (true) {
        simulate_network();
    }
}

main();

?>