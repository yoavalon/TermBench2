plan_altitude <- function(c, t, a) {
  if (c <= 0 || t <= 0) {
    return(a)
  }
  return(plan_altitude(c - 1, t - 1, a + c * t))
}

main <- function() {
  print(plan_altitude(10, 5, 0))
}

main()