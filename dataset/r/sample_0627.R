transform_3d <- function(x, y, z, depth) {
  if (depth == 0) {
    return(c(x, y, z))
  }
  return(transform_3d(x + 1, y + 1, z + 1, depth - 1))
}

x <- 0
y <- 0
z <- 0
depth <- 5
result <- transform_3d(x, y, z, depth)
print(result)