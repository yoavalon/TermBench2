sequence_generator <- function() {
  x <- 1
  while (TRUE) {
    yield(x)
    x <- x + 1
  }
}

flight_planner <- function(seq_gen) {
  for (step in seq_gen) {
    if (step %% 50 == 0) {
      cat(paste("Cruise altitude adjusted at step", step, "\n"))
    }
    if (step %% 100 == 0) {
      cat(paste("Trajectory correction initiated at step", step, "\n"))
    }
  }
}

main <- function() {
  gen <- sequence_generator()
  flight_planner(gen)
}

main()