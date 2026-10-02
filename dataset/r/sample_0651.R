vectorize_text <- function(text, vec, index) {
  if (index == nchar(text)) {
    return(vec)
  }
  char <- tolower(substr(text, index, index))
  if (char >= 'a' & char <= 'z') {
    vec[as.integer(char) - as.integer('a') + 1] <- vec[as.integer(char) - as.integer('a') + 1] + 1
  }
  return(vectorize_text(text, vec, index + 1))
}

main <- function() {
  text <- 'Hello, World!'
  vec <- rep(0, 26)
  result <- vectorize_text(text, vec, 1)
  print(result)
}

main()