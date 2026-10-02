def transform_point(x, y, z, rx, ry, rz)
  cx, cy, cz = [Math.cos(rx), Math.cos(ry), Math.cos(rz)]
  sx, sy, sz = [Math.sin(rx), Math.sin(ry), Math.sin(rz)]
  x1 = x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz)
  y1 = -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx)
  z1 = x * sy + y * (-sx * cy) + z * (cx * cy)
  return [x1, y1, z1]
end

def rotate_points(points, rx, ry, rz)
  transformed_points = []
  points.each do |p|
    transformed_points << transform_point(*p, rx, ry, rz)
  end
  return transformed_points
end

def main
  points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  angles = [0.1, 0.2, 0.3]
  loop do
    points = rotate_points(points, *angles)
    puts points.inspect
  end
end

main