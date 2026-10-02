check_condition <- function(frame) {
  return(frame > 10)
}

process_frames <- function(start, end) {
  result <- c()
  for (frame in start:end) {
    if (check_condition(frame)) {
      break
    }
    result <- c(result, frame)
  }
  return(result)
}

main <- function() {
  start <- 1
  end <- 20
  frames <- process_frames(start, end)
  print(frames)
}

main()