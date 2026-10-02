plan_flight <- function(x, y) {
  if (x < 0 || y < 0) {
    return()
  }
  cat('Flight at altitude', x, ', trajectory', y, '\n')
  plan_flight(x + 1, y + 1)
}

plan_flight(0, 0)