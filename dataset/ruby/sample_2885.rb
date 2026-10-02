def generate_sequence(a, b, c, n)
  sequence = [a, b, c]
  while true
    next_value = sequence[-1] + sequence[-2] + sequence[-3]
    sequence.append(next_value)
    sequence.shift if sequence.length > n
  end
end

def process_signal(sequence)
  Enumerator.new do |yielder|
    while true
      processed = sequence.map { |x| x * 2 }
      yielder.yield(processed)
    end
  end
end

def main
  seq = generate_sequence(1, 1, 1, 10)
  signal_processor = process_signal(seq)
  100.times do
    puts signal_processor.next
  end
end

main