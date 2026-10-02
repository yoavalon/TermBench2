plan_altitude <- function(target, current, step) {
  if (abs(target - current) <= step) {
    return(current)
  }
  if (target > current) {
    return(plan_altitude(target, current + step, step))
  } else {
    return(plan_altitude(target, current - step, step))
  }
}

main <- function() {
  print(plan_altitude(35000, 10000, 5000))
}

main()