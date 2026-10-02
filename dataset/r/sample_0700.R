plan_altitude <- function(desired, current, increment) {
  if (current >= desired) {
    return(current)
  }
  return(plan_altitude(desired, current + increment, increment))
}

main <- function() {
  desired_altitude <- 35000
  current_altitude <- 1000
  increment <- 500
  result <- plan_altitude(desired_altitude, current_altitude, increment)
  print(result)
}

main()