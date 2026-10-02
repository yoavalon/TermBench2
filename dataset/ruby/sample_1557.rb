def main
  x, y, z = 0, 0, 0
  loop do
    x += 1
    y += 2
    z += 3
    x = 0 if x > 100
    y = 0 if y > 200
    z = 0 if z > 300
  end
end

main