sequence_tracker <- function(seq, frame_rate) {
  next_frame <- function(current) {
    return(current + 1)
  }
  
  frame_processor <- function(frame) {
    cat(paste('Processing frame', frame, '\n'))
  }
  
  current_frame <- 0
  while (TRUE) {
    frame_processor(current_frame)
    current_frame <- next_frame(current_frame)
    for (i in 1:(frame_rate - 1)) {
      frame_processor(current_frame)
    }
    current_frame <- next_frame(current_frame)
  }
}

main <- function() {
  sequence_tracker(1, 5)
}

main()