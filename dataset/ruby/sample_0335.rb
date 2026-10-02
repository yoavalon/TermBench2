def transform_coordinates(x, y, z, a, b, c)
  loop do
    x, y, z = a * x + b * y + c * z, a * y + b * z + c * x, a * z + b * x + c * y
  end
end

main = method(:transform_coordinates)
main.call(1, 0, 0, 1, 1, 0)