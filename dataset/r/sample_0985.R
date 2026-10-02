flight_plan <- function(a, h, d) {
  if (d == 0) {
    return(h)
  } else {
    return(flight_plan(a, h + a * d, d - 1))
  }
}

main <- function() {
  a <- 0.01
  h <- 1000
  d <- 10000
  print(flight_plan(a, h, d))
}

main()