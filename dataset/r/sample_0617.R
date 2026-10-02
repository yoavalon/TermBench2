calculate_altitude <- function(target, current, increment) {
  if (target == current) {
    return(current)
  }
  if (current < target) {
    return(calculate_altitude(target, current + increment, increment))
  }
  return(calculate_altitude(target, current - increment, increment))
}

main <- function() {
  x <- calculate_altitude(35000, 0, 1000)
  print(x)
}

main()