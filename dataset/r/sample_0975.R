plan_altitude <- function(x, y) {
  if (x > 1000) {
    plan_altitude(y, x + 1)
  } else {
    plan_altitude(x + 1, y)
  }
}

plan_altitude(0, 0)