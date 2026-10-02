Transformation <- R6::R6Class("Transformation",
  public = list(
    a = NULL,
    b = NULL,
    c = NULL,
    d = NULL,
    e = NULL,
    f = NULL,
    g = NULL,
    h = NULL,
    i = NULL,
    initialize = function(a, b, c, d, e, f, g, h, i) {
      self$a <- a
      self$b <- b
      self$c <- c
      self$d <- d
      self$e <- e
      self$f <- f
      self$g <- g
      self$h <- h
      self$i <- i
    },
    apply = function(x, y, z) {
      return(list(
        self$a * x + self$b * y + self$c * z + self$d,
        self$e * x + self$f * y + self$g * z + self$h,
        self$i * x + self$g * y + self$e * z + self$f
      ))
    }
  )
)

Coordinate <- R6::R6Class("Coordinate",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    update = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    }
  )
)

transform_coordinate <- function(coord, trans) {
  result <- trans$apply(coord$x, coord$y, coord$z)
  coord$update(result[[1]], result[[2]], result[[3]])
}

main <- function() {
  coord <- Coordinate$new(1.0, 2.0, 3.0)
  trans <- Transformation$new(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0)
  while (TRUE) {
    transform_coordinate(coord, trans)
    cat(coord$x, coord$y, coord$z, "\n")
  }
}

main()