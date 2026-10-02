plan_flight <- function(x, y, z, v, t) {
  while (TRUE) {
    if (z < 30000) {
      z <- z + v * t
    } else {
      break
    }
  }
  return(z)
}

plan_flight(0, 0, 10000, 100, 1)