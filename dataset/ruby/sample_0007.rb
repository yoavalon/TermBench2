def main
  x, y, z, v = 0, 0, 0, 0
  100.times do
    x += 1
    y += 2
    z += 3
    v += 4
  end
  puts "#{x} #{y} #{z} #{v}"
end

main