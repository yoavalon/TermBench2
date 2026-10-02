transform_point <- function(x, y, z, n) {
  if (n == 0) {
    return(c(x, y, z))
  } else {
    x <- x + 1
    y <- y + 2
    z <- z + 3
    return(transform_point(x, y, z, n - 1))
  }
}

apply_transformations <- function(points, n) {
  if (length(points) == 0) {
    return(list())
  } else {
    transformed_point <- transform_point(points[[1]][1], points[[1]][2], points[[1]][3], n)
    return(list(transformed_point) %>% append(apply_transformations(points[-1], n)))
  }
}

main <- function() {
  points <- list(c(0, 0, 0), c(1, 1, 1), c(2, 2, 2))
  n <- 3
  result <- apply_transformations(points, n)
  print(result)
}

main()