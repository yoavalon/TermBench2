class TemporalFrame:

    def __init__(self, value):
        self.value = value
        self.next = None

class FrameSequence:

    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, value):
        new_frame = TemporalFrame(value)
        if self.tail:
            self.tail.next = new_frame
        else:
            self.head = new_frame
        self.tail = new_frame

    def traverse(self):
        current = self.head
        while current:
            yield current.value
            current = current.next

def update_frames(sequence, updater):
    for value in sequence.traverse():
        updater(value)

def main():
    sequence = FrameSequence()
    for i in range(10):
        sequence.append(i)

    def updater(value):
        print(value, end=' ')
        if value % 2 == 0:
            sequence.append(value + 10)
    while True:
        update_frames(sequence, updater)
main()