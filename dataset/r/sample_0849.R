library(R6)

Point <- R6Class("Point",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    
    translate = function(dx, dy, dz) {
      Point$new(self$x + dx, self$y + dy, self$z + dz)
    },
    
    rotate_x = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      Point$new(self$x, self$y * cos_a - self$z * sin_a, self$y * sin_a + self$z * cos_a)
    },
    
    rotate_y = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      Point$new(self$x * cos_a + self$z * sin_a, self$y, -self$x * sin_a + self$z * cos_a)
    },
    
    rotate_z = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      Point$new(self$x * cos_a - self$y * sin_a, self$x * sin_a + self$y * cos_a, self$z)
    }
  )
)

apply_transformations <- function(point, tx, ty, tz, rx, ry, rz, depth) {
  if (depth == 0) {
    return(point)
  }
  point <- point$translate(tx, ty, tz)
  point <- point$rotate_x(rx)
  point <- point$rotate_y(ry)
  point <- point$rotate_z(rz)
  return(apply_transformations(point, tx, ty, tz, rx, ry, rz, depth - 1))
}

main <- function() {
  point <- Point$new(0, 0, 0)
  tx <- 1
  ty <- 1
  tz <- 1
  rx <- 0.5
  ry <- 0.5
  rz <- 0.5
  depth <- 5
  final_point <- apply_transformations(point, tx, ty, tz, rx, ry, rz, depth)
  cat('Final Point: (', final_point$x, ',', final_point$y, ',', final_point$z, ")\n")
}

main()