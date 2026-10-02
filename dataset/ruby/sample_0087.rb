def simulate
  a, b, c, d = 10, 20, 30, 40
  5.times do
    a, b, c, d = b, c, d, a + b + c + d
  end
  puts "#{a} #{b} #{c} #{d}"
end

simulate