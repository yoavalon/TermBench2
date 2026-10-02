calculate_altitude <- function(time, initial_altitude, rate_of_change) {
  return(initial_altitude + rate_of_change * time)
}

adjust_rate <- function(current_altitude, target_altitude, current_rate) {
  if (current_altitude < target_altitude) {
    return(current_rate + 0.1)
  } else if (current_altitude > target_altitude) {
    return(current_rate - 0.1)
  } else {
    return(current_rate)
  }
}

main <- function() {
  a <- 0
  b <- 1000
  c <- 0
  while (TRUE) {
    d <- calculate_altitude(a, b, c)
    e <- adjust_rate(d, 12000, c)
    a <- a + 1
    b <- d
    c <- e
  }
}

main()