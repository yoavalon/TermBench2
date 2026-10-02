def simulate(x, y, t)
  return if t == 0
  x.times do |i|
    y.times do |j|
      if (i + j) % 2 == 0
        print '*'
      else
        print '.'
      end
    end
    puts
  end
  simulate(x, y, t - 1)
end

simulate(5, 5, 3)