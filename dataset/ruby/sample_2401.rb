def process_sequence(seq)
  states = {'open' => 0, 'closed' => 1}
  transitions = [[0, 1], [1, 0]]
  current = states['open']
  result = []
  seq.each do |x|
    current = transitions[current][x % 2 == 0 ? 0 : 1]
    result << current
  end
  return result
end

def main
  seq = [0, 1, 2, 3, 4, 5]
  puts process_sequence(seq)
end

main