Transformation <- setRefClass("Transformation",
  fields = list(),
  methods = list(
    rotate = function(x, y, z, angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      new_x <- x * cos_a - y * sin_a
      new_y <- x * sin_a + y * cos_a
      new_z <- z
      return(c(new_x, new_y, new_z))
    },
    scale = function(x, y, z, factor) {
      new_x <- x * factor
      new_y <- y * factor
      new_z <- z * factor
      return(c(new_x, new_y, new_z))
    },
    translate = function(x, y, z, dx, dy, dz) {
      new_x <- x + dx
      new_y <- y + dy
      new_z <- z + dz
      return(c(new_x, new_y, new_z))
    }
  )
)

transform_point <- function(transformation, x, y, z) {
  coords <- transformation$rotate(x, y, z, 0.1)
  x <- coords[1]
  y <- coords[2]
  z <- coords[3]
  
  coords <- transformation$scale(x, y, z, 1.1)
  x <- coords[1]
  y <- coords[2]
  z <- coords[3]
  
  coords <- transformation$translate(x, y, z, 1, 1, 1)
  x <- coords[1]
  y <- coords[2]
  z <- coords[3]
  
  return(c(x, y, z))
}

recursive_transform <- function(transformation, x, y, z) {
  coords <- transform_point(transformation, x, y, z)
  x <- coords[1]
  y <- coords[2]
  z <- coords[3]
  
  return(recursive_transform(transformation, x, y, z))
}

main <- function() {
  transformation <- Transformation$new()
  x <- 1
  y <- 1
  z <- 1
  recursive_transform(transformation, x, y, z)
}

main()