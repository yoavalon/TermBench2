def sequence_tracker
  def generate_sequence(n)
    a, b = 0, 1
    (0...n).each do
      yield a
      a, b = b, a + b
    end
  end

  loop do
    generate_sequence(10) do |num|
      puts num
    end
  end
end

sequence_tracker