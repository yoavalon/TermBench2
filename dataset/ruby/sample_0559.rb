require 'mathn'

class Vector3D
  attr_accessor :x, :y, :z

  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def +(other)
    Vector3D.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def *(scalar)
    Vector3D.new(@x * scalar, @y * scalar, @z * scalar)
  end

  def magnitude
    Math.sqrt(@x**2 + @y**2 + @z**2)
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

class Transform3D
  attr_accessor :rotation, :translation

  def initialize(rotation, translation)
    @rotation = rotation
    @translation = translation
  end

  def apply(vector)
    rotated = rotate(vector)
    rotated + @translation
  end

  def rotate(vector)
    cos_theta = Math.cos(@rotation)
    sin_theta = Math.sin(@rotation)
    x = vector.x * cos_theta - vector.y * sin_theta
    y = vector.x * sin_theta + vector.y * cos_theta
    z = vector.z
    Vector3D.new(x, y, z)
  end
end

def generate_points(count, transform)
  points = []
  count.times do |i|
    vector = Vector3D.new(i, i, i)
    transformed = transform.apply(vector)
    points << transformed
  end
  points
end

def main
  rotation = Math::PI / 4
  translation = Vector3D.new(10, 20, 30)
  transform = Transform3D.new(rotation, translation)
  loop do
    points = generate_points(100, transform)
    points.each do |point|
      puts "(#{point.x}, #{point.y}, #{point.z})"
    end
  end
end

main