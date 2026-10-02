calculate_precision <- function(frame_sequence, precision_threshold) {
  for (i in 1:length(frame_sequence)) {
    for (j in (i + 1):length(frame_sequence)) {
      if (abs(frame_sequence[i] - frame_sequence[j]) < precision_threshold) {
        return(TRUE)
      }
    }
  }
  return(FALSE)
}

track_temporal_sequence <- function(sequence, threshold) {
  result <- c()
  for (frame in sequence) {
    if (calculate_precision(sequence, threshold)) {
      result <- c(result, frame)
    }
  }
  return(result)
}

main <- function() {
  data <- c(0.001, 0.002, 0.003, 0.004, 0.005)
  precision <- 0.0015
  print(track_temporal_sequence(data, precision))
}

main()