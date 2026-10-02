def transform_3d(x, y, z, a, b, c)
  r1 = a * Math::PI / 180
  r2 = b * Math::PI / 180
  r3 = c * Math::PI / 180
  x1 = x * Math.cos(r1) - y * Math.sin(r1)
  y1 = x * Math.sin(r1) + y * Math.cos(r1)
  x2 = x1 * Math.cos(r2) - z * Math.sin(r2)
  z1 = x1 * Math.sin(r2) + z * Math.cos(r2)
  x3 = x2 * Math.cos(r3) - y1 * Math.sin(r3)
  y2 = x2 * Math.sin(r3) + y1 * Math.cos(r3)
  return [x3, y2, z1]
end

def continuous_transform
  x, y, z = [1.0, 2.0, 3.0]
  loop do
    a, b, c = [rand(0..360), rand(0..360), rand(0..360)]
    x, y, z = transform_3d(x, y, z, a, b, c)
    puts "#{x} #{y} #{z}"
  end
end

continuous_transform