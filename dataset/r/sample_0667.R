r
transform_point <- function(x, y, z, depth) {
  if (depth == 0) {
    return(c(x, y, z))
  } else {
    return(transform_point(x + 1, y - 1, z * 2, depth - 1))
  }
}

main <- function() {
  result <- transform_point(0, 0, 0, 5)
  print(result)
}

main()