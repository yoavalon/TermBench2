plan_altitude <- function(x, y, z) {
  if (x > y) {
    z <- z + 1
  } else {
    z <- z - 1
  }
  plan_altitude(x + 1, y, z)
}

plan_altitude(0, 100, 30000)