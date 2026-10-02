transform_3d <- function(x, y, z, a, b, c, depth) {
  if (depth == 0) {
    return(c(x, y, z))
  } else {
    return(transform_3d(x + a, y + b, z + c, a, b, c, depth - 1))
  }
}

main <- function() {
  initial_x <- 0
  initial_y <- 0
  initial_z <- 0
  translation_x <- 1
  translation_y <- 2
  translation_z <- 3
  recursion_depth <- 5
  result <- transform_3d(initial_x, initial_y, initial_z, translation_x, translation_y, translation_z, recursion_depth)
  print(result)
}

main()