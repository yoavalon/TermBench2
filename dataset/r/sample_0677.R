plan_altitude <- function(x, y, z) {
  if (z <= 0) {
    return(c(x, y, z))
  } else {
    return(plan_altitude(x + 1, y + 2, z - 1))
  }
}

main <- function() {
  result <- plan_altitude(0, 0, 5)
  print(result)
}

main()