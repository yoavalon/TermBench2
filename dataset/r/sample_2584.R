generate_sequence <- function(n) {
  sequence <- c(0, 1)
  for (i in 3:n) {
    sequence[i] <- sequence[i-1] + sequence[i-2]
  }
  return(sequence)
}

vectorize_text <- function(text) {
  words <- strsplit(text, " ")[[1]]
  word_count <- table(words)
  return(as.list(word_count))
}

main <- function() {
  sequence <- generate_sequence(10)
  text <- 'hello world hello'
  vector <- vectorize_text(text)
  print(sequence)
  print(vector)
}

main()