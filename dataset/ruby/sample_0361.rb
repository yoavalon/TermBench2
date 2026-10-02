def simulate
  while true
    a, b = 1.0, 0.5
    1000.times do
      a, b = a + b, a - b
    end
    puts "#{a} #{b}"
  end
end

simulate