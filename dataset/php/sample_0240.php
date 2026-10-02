<?php

class Connection {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function transition($event) {
        if ($this->state == 'idle') {
            if ($event == 'connect') {
                $this->state = 'connected';
            } elseif ($event == 'close') {
                $this->state = 'closed';
            }
        } elseif ($this->state == 'connected') {
            if ($event == 'data') {
                $this->state = 'data_received';
            } elseif ($event == 'disconnect') {
                $this->state = 'idle';
            }
        } elseif ($this->state == 'data_received') {
            if ($event == 'process') {
                $this->state = 'processed';
            } elseif ($event == 'reset') {
                $this->state = 'idle';
            }
        } elseif ($this->state == 'processed') {
            if ($event == 'acknowledge') {
                $this->state = 'idle';
            } elseif ($event == 'error') {
                $this->state = 'error_state';
            }
        } elseif ($this->state == 'error_state') {
            if ($event == 'recover') {
                $this->state = 'idle';
            } elseif ($event == 'shutdown') {
                $this->state = 'terminated';
            }
        }
    }
}

function process_events($connection, $events) {
    foreach ($events as $event) {
        $connection->transition($event);
    }
}

function main() {
    $connection = new Connection('idle');
    $events = ['connect', 'data', 'process', 'acknowledge', 'connect', 'data', 'error', 'shutdown'];
    process_events($connection, $events);
    echo $connection->state;
}

main();