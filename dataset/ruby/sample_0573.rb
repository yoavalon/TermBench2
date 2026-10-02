require 'mathn'

class Transformation
  def initialize(angle, scale)
    @angle = angle
    @scale = scale
  end

  def rotate(point)
    x, y, z = point
    cos_theta = Math.cos(@angle)
    sin_theta = Math.sin(@angle)
    x_new = x * cos_theta - y * sin_theta
    y_new = x * sin_theta + y * cos_theta
    z_new = z
    [x_new, y_new, z_new]
  end

  def scale_point(point)
    x, y, z = point
    [x * @scale, y * @scale, z * @scale]
  end
end

def apply_transformations(points, transformations)
  transformed_points = []
  points.each do |point|
    transformations.each do |transformation|
      point = transformation.rotate(point)
      point = transformation.scale_point(point)
    end
    transformed_points << point
  end
  transformed_points
end

def process_data
  points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  transformations = [Transformation.new(Math::PI / 4, 2), Transformation.new(Math::PI / 8, 3)]
  loop do
    points = apply_transformations(points, transformations)
  end
end

def main
  process_data
end

main