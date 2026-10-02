def flight_planner
  a, b, c, d, e = 10000, 5000, 2500, 1250, 625
  loop do
    a, b, c, d, e = b, c, d, e, (a + b + c + d + e) / 5.0
    puts "#{a} #{b} #{c} #{d} #{e}"
  end
end

flight_planner