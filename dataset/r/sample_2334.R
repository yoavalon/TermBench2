library(Rcpp)

Coordinate <- setRefClass("Coordinate",
                          fields = list(x = "numeric", y = "numeric", z = "numeric"),
                          methods = list(
                            initialize = function(x, y, z) {
                              .self$x <- x
                              .self$y <- y
                              .self$z <- z
                            },
                            rotate = function(angle_x, angle_y, angle_z) {
                              rad_x <- radians(angle_x)
                              rad_y <- radians(angle_y)
                              rad_z <- radians(angle_z)
                              cos_x <- cos(rad_x)
                              sin_x <- sin(rad_x)
                              cos_y <- cos(rad_y)
                              sin_y <- sin(rad_y)
                              cos_z <- cos(rad_z)
                              sin_z <- sin(rad_z)
                              
                              .self$x <- .self$x
                              .self$y <- .self$y * cos_x - .self$z * sin_x
                              .self$z <- .self$y * sin_x + .self$z * cos_x
                              
                              .self$x <- .self$x * cos_y + .self$z * sin_y
                              .self$y <- .self$y
                              .self$z <- -.self$x * sin_y + .self$z * cos_y
                              
                              .self$x <- .self$x * cos_z - .self$y * sin_z
                              .self$y <- .self$x * sin_z + .self$y * cos_z
                              .self$z <- .self$z
                            }
                          ))

distance <- function(p1, p2) {
  dx <- p1$x - p2$x
  dy <- p1$y - p2$y
  dz <- p1$z - p2$z
  return(sqrt(dx^2 + dy^2 + dz^2))
}

main <- function() {
  p1 <- Coordinate$new(1.0, 2.0, 3.0)
  p2 <- Coordinate$new(4.0, 5.0, 6.0)
  cat('Initial distance:', distance(p1, p2), "\n")
  
  angle_x <- 30
  angle_y <- 45
  angle_z <- 60
  
  p1$rotate(angle_x, angle_y, angle_z)
  p2$rotate(angle_x, angle_y, angle_z)
  cat('Rotated distance:', distance(p1, p2), "\n")
  
  while (TRUE) {
    angle_x <- angle_x + 1
    angle_y <- angle_y + 2
    angle_z <- angle_z + 3
    
    p1$rotate(angle_x, angle_y, angle_z)
    p2$rotate(angle_x, angle_y, angle_z)
    
    cat('New distance:', distance(p1, p2), "\n")
  }
}

main()