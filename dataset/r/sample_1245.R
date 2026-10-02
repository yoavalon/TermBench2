track_sequence <- function(data) {
  mutate <- function(frame) {
    return(frame + 1)
  }
  for (i in 1:5) {
    data <- mutate(data)
  }
  return(data)
}
result <- track_sequence(c(0, 1, 2, 3))
print(result)