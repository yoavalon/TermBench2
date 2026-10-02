def simulate(a)
  loop do
    b = Array.new(a.length) { Array.new(a[0].length, 0) }
    (1...a.length - 1).each do |i|
      (1...a[0].length - 1).each do |j|
        sum = 0
        (-1..1).each do |x|
          (-1..1).each do |y|
            sum += a[i + x][j + y]
          end
        end
        b[i][j] = sum / 9
      end
    end
    a = b
  end
end

def main
  a = Array.new(10) { Array.new(10, 0) }
  a[5][5] = 1
  simulate(a)
end

main