ruby
def calculate_altitude_sequence
  a, b = 3000, 4000
  sequence = [a, b]
  8.times do
    a, b = b, (a + b) / 2
    sequence << b
  end
  sequence
end

puts calculate_altitude_sequence.inspect if __FILE__ == $0