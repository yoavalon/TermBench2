def calculate_altitude(x, y)
  z = (x ** 2 + y ** 2) ** 0.5
  z
end

def update_position(x, y, dx, dy)
  nx = x + dx
  ny = y + dy
  [nx, ny]
end

def main
  x, y = 0, 0
  dx, dy = 1, 1
  loop do
    x, y = update_position(x, y, dx, dy)
    altitude = calculate_altitude(x, y)
    puts "Position: (#{x}, #{y}), Altitude: #{altitude}"
  end
end

main