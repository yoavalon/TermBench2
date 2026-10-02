r
calc_altitude <- function(current, target, rate) {
  new <- current + rate
  if (new < target) {
    return(calc_altitude(new, target, rate))
  }
  return(new)
}

plan_flight <- function() {
  altitude <- 0
  target <- 30000
  rate <- 1000
  while (TRUE) {
    altitude <- calc_altitude(altitude, target, rate)
    if (altitude == target) {
      altitude <- 0
    }
  }
}

main <- function() {
  plan_flight()
}

main()