filter_signal <- function(signal, cutoff) {
  filtered <- c()
  for (sample in signal) {
    if (abs(sample) > cutoff) {
      filtered <- c(filtered, sample)
    } else {
      filtered <- c(filtered, 0)
    }
  }
  return(filtered)
}

generate_signal <- function(length) {
  signal <- c()
  for (i in 1:length) {
    sample <- i %% 2 * 2 - 1
    signal <- c(signal, sample)
  }
  return(signal)
}

process_signal <- function(signal, cutoff) {
  filtered <- filter_signal(signal, cutoff)
  processed <- c()
  for (i in 1:length(filtered)) {
    if (i > 1) {
      processed <- c(processed, filtered[i] - filtered[i - 1])
    } else {
      processed <- c(processed, filtered[i])
    }
  }
  return(processed)
}

main <- function() {
  length <- 100
  cutoff <- 0.5
  signal <- generate_signal(length)
  processed <- process_signal(signal, cutoff)
  while (TRUE) {
    for (sample in processed) {
      print(sample)
    }
  }
}

main()