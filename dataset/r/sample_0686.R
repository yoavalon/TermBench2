calculate_altitude <- function(x, y, z, target, max_iter = 100) {
  if (x >= target || max_iter <= 0) {
    return(z)
  } else {
    return(calculate_altitude(x + 1, y, z + 0.1, target, max_iter - 1))
  }
}
result <- calculate_altitude(0, 0, 10000, 100000)
print(result)