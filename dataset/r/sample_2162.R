track_temporal_frame_sequence <- function() {

  update_position <- function(x) {
    return(x + 0.0001)
  }
  
  x <- 0.0
  while (TRUE) {
    x <- update_position(x)
    print(x)
  }
}

track_temporal_frame_sequence()