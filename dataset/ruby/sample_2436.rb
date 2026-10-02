def main
  n = 10
  a, b = 0, 1
  sequence = [a, b]
  (2...n).each do |i|
    a, b = b, a + b
    sequence.push(b)
  end
  puts sequence.inspect
end

main