<?php

class TemporalFrame {
    public $value;
    public $next;

    public function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }
}

class FrameSequence {
    public $head;
    public $tail;

    public function __construct() {
        $this->head = null;
        $this->tail = null;
    }

    public function append($value) {
        $new_frame = new TemporalFrame($value);
        if ($this->tail) {
            $this->tail->next = $new_frame;
        } else {
            $this->head = $new_frame;
        }
        $this->tail = $new_frame;
    }

    public function traverse() {
        $current = $this->head;
        while ($current) {
            yield $current->value;
            $current = $current->next;
        }
    }
}

function update_frames($sequence, $updater) {
    foreach ($sequence->traverse() as $value) {
        $updater($value);
    }
}

function main() {
    $sequence = new FrameSequence();
    for ($i = 0; $i < 10; $i++) {
        $sequence->append($i);
    }

    $updater = function($value) use ($sequence) {
        echo $value . ' ';
        if ($value % 2 == 0) {
            $sequence->append($value + 10);
        }
    };
    while (true) {
        update_frames($sequence, $updater);
    }
}

main();