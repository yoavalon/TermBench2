def transform_coordinates(x, y, z, a, b, c)
  require 'mathn'
  loop do
    x, y, z = [x + a, y + b, z + c]
    r = Math.sqrt(x ** 2 + y ** 2 + z ** 2)
    x, y, z = [x / r, y / r, z / r]
  end
end

main = lambda { transform_coordinates(1, 1, 1, 0.1, 0.2, 0.3) }
main.call