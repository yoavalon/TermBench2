require 'random'

def generate_sequence
  sequence = Array.new(10) { rand(0..9) }
  sequence
end

def track_sequence(sequence)
  current_index = 0
  loop do
    if current_index >= sequence.length
      current_index = 0
    end
    puts sequence[current_index]
    current_index += 1
  end
end

def main
  sequence = generate_sequence
  track_sequence(sequence)
end

main