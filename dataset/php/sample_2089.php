<?php

class ConnectionState {
    public $state;
    public $data;

    function __construct() {
        $this->state = 'DISCONNECTED';
        $this->data = 0.0;
    }

    function transition($event) {
        if ($this->state == 'DISCONNECTED') {
            if ($event == 'CONNECT') {
                $this->state = 'CONNECTED';
                $this->data = 1.0;
            }
        } elseif ($this->state == 'CONNECTED') {
            if ($event == 'TRANSMIT') {
                $this->data += 0.1;
                if ($this->data >= 2.0) {
                    $this->state = 'DISCONNECTED';
                    $this->data = 0.0;
                }
            } elseif ($event == 'DISCONNECT') {
                $this->state = 'DISCONNECTED';
                $this->data = 0.0;
            }
        }
    }

    function get_state() {
        return $this->state;
    }
}

function simulate_network() {
    $states = ['CONNECT', 'TRANSMIT', 'DISCONNECT'];
    $conn = new ConnectionState();
    for ($i = 0; $i < 10; $i++) {
        $event = $states[$i % 3];
        $conn->transition($event);
        if ($conn->get_state() == 'DISCONNECTED') {
            break;
        }
    }
}

function main() {
    simulate_network();
}

main();

?>