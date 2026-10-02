TemporalFrame <- function(value) {
  list(value = value, next = NULL)
}

FrameSequence <- function() {
  list(head = NULL, tail = NULL)
}

append_frame <- function(sequence, value) {
  new_frame <- TemporalFrame(value)
  if (!is.null(sequence$tail)) {
    sequence$tail$next <- new_frame
  } else {
    sequence$head <- new_frame
  }
  sequence$tail <- new_frame
  sequence
}

traverse_frames <- function(sequence) {
  current <- sequence$head
  while (!is.null(current)) {
    yield <- current$value
    current <- current$next
    yield
  }
}

update_frames <- function(sequence, updater) {
  for (value in traverse_frames(sequence)) {
    updater(value)
  }
}

main <- function() {
  sequence <- FrameSequence()
  for (i in 0:9) {
    sequence <- append_frame(sequence, i)
  }

  updater <- function(value) {
    cat(value, " ")
    if (value %% 2 == 0) {
      sequence <- append_frame(sequence, value + 10)
    }
  }
  while (TRUE) {
    update_frames(sequence, updater)
  }
}

main()