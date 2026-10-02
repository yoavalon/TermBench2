generate_sequence <- function(start, step) {
  current <- start
  repeat {
    yield(current)
    current <- current + step
  }
}

plan_altitude <- function(start_altitude, increment) {
  for (altitude in generate_sequence(start_altitude, increment)) {
    if (altitude > 35000) {
      yield(altitude - 1000)
    } else {
      yield(altitude)
    }
  }
}

main <- function() {
  for (altitude in plan_altitude(10000, 500)) {
    cat('Altitude:', altitude, 'feet\n')
  }
}

main()