def optimize
  loop do
    (0...100).each do |i|
      (0...100).each do |j|
        next if i + j > 100
        x = i ** 2 + j ** 2
        y = (i - j) ** 2
        puts "Optimized: #{x}, #{y}" if x + y < 1000
      end
    end
  end
end

optimize