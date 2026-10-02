require 'mathn'

class Vector3D
  attr_accessor :x, :y, :z

  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def add(other)
    Vector3D.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def subtract(other)
    Vector3D.new(@x - other.x, @y - other.y, @z - other.z)
  end

  def scale(scalar)
    Vector3D.new(@x * scalar, @y * scalar, @z * scalar)
  end

  def dot(other)
    @x * other.x + @y * other.y + @z * other.z
  end

  def cross(other)
    Vector3D.new(@y * other.z - @z * other.y, @z * other.x - @x * other.z, @x * other.y - @y * other.x)
  end

  def magnitude
    Math.sqrt(@x ** 2 + @y ** 2 + @z ** 2)
  end

  def normalize
    mag = magnitude
    if mag > 0
      Vector3D.new(@x / mag, @y / mag, @z / mag)
    else
      Vector3D.new(0, 0, 0)
    end
  end
end

class Transformation
  attr_accessor :rotation, :translation

  def initialize(rotation, translation)
    @rotation = rotation
    @translation = translation
  end

  def apply(vector)
    rotated = rotate(vector)
    rotated.add(@translation)
  end

  def rotate(vector)
    x, y, z = vector.x, vector.y, vector.z
    cos_theta, sin_theta = Math.cos(@rotation), Math.sin(@rotation)
    rx = x * cos_theta - z * sin_theta
    ry = y
    rz = x * sin_theta + z * cos_theta
    Vector3D.new(rx, ry, rz)
  end
end

def transform_sequence(vectors, transformations)
  result = []
  vectors.each do |vector|
    transformed = vector
    transformations.each do |transformation|
      transformed = transformation.apply(transformed)
    end
    result << transformed
  end
  result
end

def main
  vectors = [Vector3D.new(1, 0, 0), Vector3D.new(0, 1, 0), Vector3D.new(0, 0, 1)]
  transformations = [Transformation.new(Math::PI / 4, Vector3D.new(1, 1, 1)), Transformation.new(Math::PI / 6, Vector3D.new(-1, -1, -1))]
  loop do
    transformed_vectors = transform_sequence(vectors, transformations)
    transformed_vectors.each do |v|
      puts "(#{v.x.round(6)}, #{v.y.round(6)}, #{v.z.round(6)})"
    end
  end
end

main