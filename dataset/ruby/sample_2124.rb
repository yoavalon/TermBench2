ruby
def cellular_automata(n)
  a = Array.new(n) { Array.new(n, 0) }
  loop do
    b = Array.new(n) { Array.new(n, 0) }
    (0...n).each do |i|
      (0...n).each do |j|
        b[i][j] = (a[i][j] + a[(i - 1) % n][j] + a[i][(j - 1) % n] + a[(i + 1) % n][j] + a[i][(j + 1) % n]) / 5.0
      end
    end
    a = b
  end
end

cellular_automata(10)