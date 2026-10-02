TransformationMatrix <- function(a, b, c, d, e, f, g, h, i) {
  this <- list()
  this$a <- a
  this$b <- b
  this$c <- c
  this$d <- d
  this$e <- e
  this$f <- f
  this$g <- g
  this$h <- h
  this$i <- i
  
  this$apply <- function(x, y, z) {
    new_x <- this$a * x + this$b * y + this$c * z
    new_y <- this$d * x + this$e * y + this$f * z
    new_z <- this$g * x + this$h * y + this$i * z
    return(c(new_x, new_y, new_z))
  }
  
  return(this)
}

CoordinateTransformer <- function(matrix) {
  this <- list()
  this$matrix <- matrix
  
  this$transform_point <- function(point) {
    x <- point[1]
    y <- point[2]
    z <- point[3]
    return(this$matrix$apply(x, y, z))
  }
  
  this$transform_points <- function(points) {
    results <- list()
    for (p in points) {
      results[[length(results) + 1]] <- this$transform_point(p)
    }
    return(results)
  }
  
  return(this)
}

GeometryAnalysis <- function(transformer) {
  this <- list()
  this$transformer <- transformer
  
  this$analyze <- function(points) {
    transformed_points <- this$transformer$transform_points(points)
    results <- list()
    for (point in transformed_points) {
      results[[length(results) + 1]] <- this$calculate_distance(point)
    }
    return(results)
  }
  
  this$calculate_distance <- function(point) {
    x <- point[1]
    y <- point[2]
    z <- point[3]
    return(sqrt(x^2 + y^2 + z^2))
  }
  
  return(this)
}

main <- function() {
  matrix <- TransformationMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1)
  transformer <- CoordinateTransformer(matrix)
  analysis <- GeometryAnalysis(transformer)
  points <- list(c(1.0, 2.0, 3.0), c(4.0, 5.0, 6.0), c(7.0, 8.0, 9.0))
  results <- analysis$analyze(points)
  print(results)
}

main()