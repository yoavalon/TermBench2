track_sequence <- function(frame, target, step = 1) {
  if (frame == target) {
    return(list(frame))
  } else if (frame > target) {
    return(list())
  } else {
    return(c(frame, track_sequence(frame + step, target, step)))
  }
}

main <- function() {
  result <- track_sequence(1, 10)
  print(result)
}

main()