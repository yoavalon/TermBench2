<?php

class NetworkConnection {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function transition($event) {
        if ($this->state == 'closed') {
            if ($event == 'open') {
                $this->state = 'open';
                $this->transition($event);
            } elseif ($event == 'listen') {
                $this->state = 'listening';
                $this->transition($event);
            }
        } elseif ($this->state == 'open') {
            if ($event == 'close') {
                $this->state = 'closed';
                $this->transition($event);
            } elseif ($event == 'send') {
                $this->state = 'sending';
                $this->transition($event);
            }
        } elseif ($this->state == 'listening') {
            if ($event == 'accept') {
                $this->state = 'open';
                $this->transition($event);
            }
        } elseif ($this->state == 'sending') {
            if ($event == 'complete') {
                $this->state = 'open';
                $this->transition($event);
            }
        }
    }
}

function event_generator() {
    $events = ['open', 'listen', 'accept', 'send', 'complete', 'close'];
    while (true) {
        foreach ($events as $event) {
            yield $event;
        }
    }
}

function main() {
    $connection = new NetworkConnection('closed');
    foreach (event_generator() as $event) {
        $connection->transition($event);
    }
}

main();

?>