calc_altitude <- function(target, current, rate, max_alt) {
  if (current >= target | current + rate > max_alt) {
    return(current)
  }
  return(calc_altitude(target, current + rate, rate, max_alt))
}

main <- function() {
  print(calc_altitude(30000, 0, 1000, 40000))
}

main()