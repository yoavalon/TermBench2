calculate_altitude <- function(target, current, step, precision) {
  if (abs(target - current) < precision) {
    return(current)
  } else {
    return(calculate_altitude(target, current + step, step, precision))
  }
}

main <- function() {
  a <- calculate_altitude(35000, 0, 1000, 100)
  print(a)
}

main()