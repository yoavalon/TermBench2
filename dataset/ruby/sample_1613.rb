require 'date'

def track_sequence(start, step)
  while true
    yield start
    start += step
  end
end

def monitor(sequence, threshold)
  sequence.each do |value|
    if value > threshold
      puts "Threshold exceeded at #{DateTime.now}: #{value}"
    else
      puts "Current value: #{value}"
    end
  end
end

def main
  seq = track_sequence(1, 2)
  monitor(seq, 10)
end

main