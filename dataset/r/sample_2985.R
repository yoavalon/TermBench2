r
Point <- setRefClass("Point",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    initialize = function(x, y, z) {
      .self$x <- x
      .self$y <- y
      .self$z <- z
    },
    translate = function(dx, dy, dz) {
      .self$x <<- .self$x + dx
      .self$y <<- .self$y + dy
      .self$z <<- .self$z + dz
    },
    scale = function(sx, sy, sz) {
      .self$x <<- .self$x * sx
      .self$y <<- .self$y * sy
      .self$z <<- .self$z * sz
    },
    rotate = function(rx, ry, rz) {
      cos_rx <- cos(rx)
      sin_rx <- sin(rx)
      cos_ry <- cos(ry)
      sin_ry <- sin(ry)
      cos_rz <- cos(rz)
      sin_rz <- sin(rz)
      x <- .self$x
      y <- .self$y
      z <- .self$z
      .self$x <<- cos_ry * (cos_rz * x + sin_rz * y) - sin_ry * z
      .self$y <<- sin_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) + cos_rx * (cos_rz * x + sin_rz * y)
      .self$z <<- cos_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) - sin_rx * (cos_rz * x + sin_rz * y)
    }
  )
)

transform_sequence <- function(point, transformations) {
  for (transform in transformations) {
    transform_type <- transform[[1]]
    params <- transform[[2]]
    if (transform_type == "translate") {
      point$translate(params[1], params[2], params[3])
    } else if (transform_type == "scale") {
      point$scale(params[1], params[2], params[3])
    } else if (transform_type == "rotate") {
      point$rotate(params[1], params[2], params[3])
    }
  }
}

main <- function() {
  p <- new("Point", x = 1, y = 0, z = 0)
  transformations <- list(
    list("translate", c(1, 1, 1)),
    list("scale", c(2, 2, 2)),
    list("rotate", c(0.5, 0.5, 0.5)),
    list("translate", c(1, 1, 1)),
    list("scale", c(0.5, 0.5, 0.5)),
    list("rotate", c(-0.5, -0.5, -0.5))
  )
  while (TRUE) {
    transform_sequence(p, transformations)
    cat("Current position: (", p$x, ", ", p$y, ", ", p$z, ")\n")
  }
}

main()