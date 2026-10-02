track_sequence <- function() {
  data <- list()
  while (TRUE) {
    frame_data <- list(frame = length(data), timestamp = length(data) * 1000)
    data[[length(data) + 1]] <- frame_data
    print(frame_data)
  }
}

track_sequence()