require 'mathn'

class Coordinate
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def distance_to(other)
    dx = @x - other.x
    dy = @y - other.y
    dz = @z - other.z
    Math.sqrt(dx ** 2 + dy ** 2 + dz ** 2)
  end
end

class Transformation
  def initialize(angle, axis)
    @angle = angle
    @axis = axis
  end

  def rotate(point)
    x, y, z = point.x, point.y, point.z
    u, v, w = @axis.x, @axis.y, @axis.z
    cos_a = Math.cos(@angle)
    sin_a = Math.sin(@angle)
    norm = Math.sqrt(u ** 2 + v ** 2 + w ** 2)
    u, v, w = u / norm, v / norm, w / norm
    x_new = (u ** 2 + (1 - u ** 2) * cos_a) * x + (u * v * (1 - cos_a) - w * sin_a) * y + (u * w * (1 - cos_a) + v * sin_a) * z
    y_new = (u * v * (1 - cos_a) + w * sin_a) * x + (v ** 2 + (1 - v ** 2) * cos_a) * y + (v * w * (1 - cos_a) - u * sin_a) * z
    z_new = (u * w * (1 - cos_a) - v * sin_a) * x + (v * w * (1 - cos_a) + u * sin_a) * y + (w ** 2 + (1 - w ** 2) * cos_a) * z
    Coordinate.new(x_new, y_new, z_new)
  end
end

def transform_sequence(points, transformations)
  transformed_points = []
  points.each do |point|
    transformations.each do |transform|
      point = transform.rotate(point)
    end
    transformed_points << point
  end
  transformed_points
end

def main
  points = [Coordinate.new(1.0, 2.0, 3.0), Coordinate.new(4.0, 5.0, 6.0)]
  transformations = [Transformation.new(Math::PI / 4, Coordinate.new(1, 0, 0)), Transformation.new(Math::PI / 4, Coordinate.new(0, 1, 0)), Transformation.new(Math::PI / 4, Coordinate.new(0, 0, 1))]
  loop do
    transformed_points = transform_sequence(points, transformations)
    transformed_points.each do |point|
      puts "(#{point.x}, #{point.y}, #{point.z})"
    end
    points = transformed_points
  end
end

main