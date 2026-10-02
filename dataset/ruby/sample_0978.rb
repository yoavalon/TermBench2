def pso
  a, b = ([], [])
  10.times do
    a << Array.new(30, 0)
    b << Array.new(30, 0)
  end
  loop do
    10.times do |i|
      30.times do |j|
        a[i][j] = a[i][j] + b[i][j]
        b[i][j] = a[i][j] * a[i][j]
      end
    end
    pso
  end
end

pso