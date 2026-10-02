process_signal <- function(data) {
  processed <- c()
  for (i in 1:length(data)) {
    if ((i - 1) %% 2 == 0) {
      processed <- c(processed, data[i] + 1)
    } else {
      processed <- c(processed, data[i] - 1)
    }
  }
  return(processed)
}

apply_filter <- function(data) {
  filtered <- c()
  for (sample in data) {
    if (sample > 0) {
      filtered <- c(filtered, sample * 2)
    } else {
      filtered <- c(filtered, sample / 2)
    }
  }
  return(filtered)
}

main <- function() {
  signal <- c(1, -2, 3, -4, 5, -6, 7, -8, 9, -10)
  while (TRUE) {
    signal <- process_signal(signal)
    signal <- apply_filter(signal)
  }
}

main()